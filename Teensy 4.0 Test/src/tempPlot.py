import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Open de seriële poort
ser = serial.Serial('COM10', 115200)  # Pas de COM-poort aan op basis van je setup

# Initialiseer lijsten voor tijd en temperatuur
times = []
temperatures = []
n_fib_lijst = []
# Setup plot
fig, ax1 = plt.subplots()
line1, = ax1.plot([], [], 'r-')
ax1.set_xlim(0, 50)
ax1.set_ylim(35, 70)
ax1.set_xlabel('Tijd (s)')
ax1.set_ylabel('Temperatuur (°C)')
ax1.set_title('Real-Time Temperatuur Monitoring')
ax2 = ax1.twinx()
ax2.set_ylabel('N Fibonacci', color='tab:blue')
scatter, = ax2.plot([], [], 'bo', label='Additional Data')  # Gebruik plot met punten
ax2.tick_params(axis='y', labelcolor='tab:blue')
ax2.set_ylim(0, 80000)  # Pas de y-lim aan op basis van je data

def init():
    line1.set_data([], [])
    scatter.set_data([], [])
    return line1, scatter

def update(frame):
    global times, temperatures, n_fib_lijst

    # Lees een regel van de seriële poort
    try:
        line_serial = ser.readline().decode('utf-8').strip()
        if line_serial:
            print(f"Received data: {line_serial}")  # Debug print
            data = line_serial.split(',')
            if len(data) == 3:
                try:
                    n_fib = float(data[0])
                    currenttime = float(data[1])
                    temperature = float(data[2])
                    n_fib_lijst.append(n_fib)
                    times.append(currenttime)
                    temperatures.append(temperature)
                    # Update plot
                    # ax.set_xlim(0, times[-1])
                    # ax.set_ylim(0, max(temperatures) + 1)  # Dynamisch y-lim
                    line1.set_data(times, temperatures)
                    scatter.set_data(times, n_fib_lijst)
                    print(f"Times: {times}")  # Debug print
                    print(f"Temperatures: {temperatures}")  # Debug print
                except ValueError as e:
                    print(f"ValueError: {e}")  # Debug print
    except serial.SerialException as e:
        print(f"SerialException: {e}")  # Debug print

    return line1, scatter

# Animatie instellen
ani = animation.FuncAnimation(fig, update, init_func=init, blit=True, interval=1000)

try:
    plt.show()
except KeyboardInterrupt:
    print("Gegevensverzameling gestopt.")
finally:
    ser.close()
