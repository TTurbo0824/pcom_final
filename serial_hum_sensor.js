let serial; // variable to hold an instance of the serialport library
let portName = '/dev/ttyACM0'; // fill in your serial port name here
let inData; // for incoming serial data
let sensors;

function serverConnected() {
  console.log('connected to server.');
}


function serialError(err) {
  console.log('Something went wrong with the serial port.');
}

function serialEvent() {
  inData = serial.readStringUntil("\n");
  console.log(inData);
  if (inData.length > 0) {
    sensors = split(inData, ',');
    console.log(sensors);

    if (sensors.length > 1) {
      background(0);
      fill(255);
      text("humidity: " + sensors[0] / 100 + '%, temperature: ' + sensors[1] / 100 + '%', 30, 30);
    }
  }
}

function setup() {
  createCanvas(400, 300);

  // serial
  serial = new p5.SerialPort();
  serial.on('list', printList);
  serial.open(portName);
  serial.on('data', serialEvent);
  serial.on('connected', serverConnected);
  serial.on('error', serialError);
}

function printList(portList) {
  for (let i = 0; i < portList.length; i++) {
    console.log(i + " " + portList[i]);
  }
}
//Then here’s your draw() function:
