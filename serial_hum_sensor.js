let serial;          // variable to hold an instance of the serialport library
let portName = '/dev/ttyACM0'; // fill in your serial port name here
let inData;                             // for incoming serial data
let serial;

function serialEvent() {
  inData = Number(serial.read());
}

function setup() {
  createCanvas(400, 300);

  // serial
  serial = new p5.SerialPort(document.location.hostname);
  // set callback functions for list and data events:
  serial.on('list', printList);
  serial.on('data', serialEvent);
  // open the serial port:
  serial.open(portName);
}

//Then here’s your draw() function:
function draw() {
  background(0);
  fill(255);
  text("humidity: " + inData, 30, 30);
}
