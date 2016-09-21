#!/usr/bin/python
import serial
import numpy as np
from matplotlib import pyplot as plt

# Se inicia la comunicacion serial
arduinoPort = serial.Serial('/dev/ttyUSB0', 9600)
plt.ion()
plt.xlabel('Tiempo (ms)')
plt.ylabel('Voltaje (V)')
plt.title('Labo3: Multimetro')
plot.grid(True)

while True:
	signal = arduinoPort.readline()
	C = signal.split("\t") # C contiene las coordenas X,Y
	plt.plot(C[0], C[1])
	plt.show()
