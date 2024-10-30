BRAUDRATE = 9600
PORT = /dev/cu.usbmodem11201
SRC_PATH = .

all: upload

check:
	arduino-cli compile --fqbn arduino:avr:uno $(SRC_PATH)

upload:
	arduino-cli compile --fqbn arduino:avr:uno --port $(PORT) --upload $(SRC_PATH)

list:
	arduino-cli board list

serial:
	arduino-cli monitor -p $(PORT) -b arduino:avr:uno --config $(BRAUDRATE)