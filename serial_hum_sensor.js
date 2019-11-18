var serial;          // variable to hold an instance of the serialport library
var portName = '/dev/cu.usbmodem1421';  // fill in your serial port name here
var inData;                             // for incoming serial data

function serialEvent() {
  inData = Number(serial.read());
}
// Although you’re reading the incoming data, you’re not displaying it anywhere yet. Add a draw() function and print the sensor value to the screen. Start by adding a createCanvas() to the top of your setup() like so:

function setup() {
  createCanvas(400, 300);
}

//Then here’s your draw() function:
function draw() {
  background(0);
  fill(255);
  text("humidity: " + inData, 30, 30);
}
