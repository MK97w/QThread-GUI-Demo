# QThread-GUI-Demo

FILE OPERATIONS ARE NOT ADDED YET


A "heavy work"/"blocking" for-loop is running on a seperate thread. This thread is created when button is pressed.

On each iteration of for-loop, a signal is emitted to main thread to update the value of progressbar. Whole operation doesnt block/hang the GUI
