BRAUDRATE = 
PORT = 
SRC_PATH = .

all: upload

upload:
	arduino-cli compile --fqbn arduino:avr:uno --port $(PORT) --upload $(SRC_PATH)

list:
	arduino-cli board list

serial:
	arduino-cli monitor -p $(PORT) -b arduino:avr:uno --config $(BRAUDRATE)