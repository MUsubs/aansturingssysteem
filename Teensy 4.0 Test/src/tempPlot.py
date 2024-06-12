import serial
import matplotlib.pyplot as plt

# Open de seriële poort
ser = serial.Serial('COM10', 9600)  # Pas de COM-poort aan op basis van je setup
ser.write(b'start\n')

# Initialiseer lijsten voor tijd en temperatuur
times = []
temperatures = []
n_fib_lijst = []

# Setup plot
fig, ax1 = plt.subplots(figsize=(12,6))
line1, = ax1.plot([], [], 'r-')
ax1.set_ylim(35, 65)
ax1.set_xlabel('Tijd (s)')
ax1.set_ylabel('Temperatuur (°C)')
ax1.set_title('Real-Time Temperatuur Monitoring')

ax2 = ax1.twinx()
ax2.set_ylabel('N Fibonacci', color='tab:blue')
scatter, = ax2.plot([], [], 'bo', label='Additional Data')  # Gebruik plot met punten
ax2.tick_params(axis='y', labelcolor='tab:blue')
ax2.set_ylim(0, 80000)  # Pas de y-lim aan op basis van je data

def update():
    global times, temperatures, n_fib_lijst

    # Lees een regel van de seriële poort
    try:
        line_serial = ser.readline().decode('utf-8').strip()
        if line_serial:
            print(f"Received data: {line_serial}")  # Debug print
            if line_serial == "finished":
                raise KeyboardInterrupt
            
            data = line_serial.split(',')
            if len(data) == 3:
                try:
                    n_fib = float(data[0]) 
                    currenttime = float(data[1]) / 1000000.0
                    temperature = float(data[2])
                    n_fib_lijst.append(n_fib)
                    times.append(currenttime)
                    temperatures.append(temperature)

                    # Update plot
                    if len(times) > 1:
                        ax1.set_xlim(times[0], times[-1])
                        ax2.set_xlim(times[0], times[-1])
                    line1.set_data(times, temperatures)
                    scatter.set_data(times, n_fib_lijst)

                    fig.canvas.draw()
                    fig.canvas.flush_events()

                    print(f"Times: {times}")  #debug
                    print(f"Temperatures: {temperatures}")  
                except ValueError as e:
                    print(f"ValueError: {e}") 
    except serial.SerialException as e:
        print(f"SerialException: {e}")  

plt.ion()  # interactieve modus aan
fig.show()

try:
    while True:
        update()
except KeyboardInterrupt:
    print("Gegevensverzameling gestopt.")
finally:
    ser.close()
    plt.ioff()  # Interactive mode off
    plt.show()  # Ensure the plot stays open after the loop

