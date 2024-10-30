import event
import cyberpi
import gamepad
import mbot2

@event.start
def on_start():

	while True:
		
		if gamepad.is_key_pressed('L1') or gamepad.is_key_pressed('R1') or gamepad.is_key_pressed('L2') or gamepad.is_key_pressed('R2'):
			
			if gamepad.is_key_pressed('R1') and gamepad.is_key_pressed('R2') or gamepad.is_key_pressed('L1') and gamepad.is_key_pressed('L2'):
				mbot2.EM_set_power(0,"EM1")
				mbot2.EM_set_power(0,"EM2")

			if gamepad.is_key_pressed('R1'):
				mbot2.EM_set_power(-80,"EM1")

			if gamepad.is_key_pressed('L1'):
				mbot2.EM_set_power(80,"EM2")

			if gamepad.is_key_pressed('R2'):
				mbot2.EM_set_power(80,"EM1")

			if gamepad.is_key_pressed('L2'):
				mbot2.EM_set_power(-80,"EM2")

		else:
			mbot2.EM_set_power(0,"EM1")
			mbot2.EM_set_power(0,"EM2")
