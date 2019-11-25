// inspired by Daniel Shiffman's code with texrt video
let libra = ['yellow', 'ribbon', 'march', 'belief', 'gray', 'apple', 'data', 'escape', 'side', 'candle', 'taiwan', 'voice', 'revolution', 'rainbow', 'power', 'support', 'peace', 'cold', 'indifferent', 'share'];
let words = [];
let occurrences = [];
let lang, speechRec;
let w;
let freq = {};
let options = {
  baudRate: 115200
};
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
      fill(0);
      rect(0, height / 2, width, height);
      fill(255);
      textSize(32);
      text("humidity: " + sensors[0] / 100 + '%, temperature: ' + sensors[1] / 100 + '%', width / 5, 2 * height / 3);
    }
  }
}

function setup() {
  createCanvas(windowWidth, windowHeight);
  background(0);
  lang = 'en-US';
  speechRec = new p5.SpeechRec(lang, gotSpeech);
  let continuous = true;
  let interim = true;
  speechRec.start(continuous, interim);

  // serial
  serial = new p5.SerialPort();
  serial.on('list', printList);
  serial.open(portName, options);
  serial.on('data', serialEvent);
  serial.on('connected', serverConnected);
  serial.on('error', serialError);
}

function gotSpeech() {
  if (speechRec.resultValue) {
    //createP(speechRec.resultString);
    w = speechRec.resultString;
    if (w !== words[(words.length - 1)]) {
      words.push(w);
    }


	
    for (let i = 0; i < libra.length; i++) {
        if (words[words.length - 1] == libra[i]) {
          noStroke();
          fill(0);
          rect(0, 0, width, height / 2);
          fill(255);
          textSize(70);
          text(words[words.length - 1], width / 5, height / 3);
          if (words[(words.length - 1)] in freq){
            freq[(words.length -1)] += 1;
            }else{
            freq[(words.length -1)] = 1;
            }
	  console.log(freq);	
          serial.write(i+1);
          console.log("got from ard");
        } else {
          serial.write(0);
        }
      }
    }
  }

function printList(portList) {
  for (let i = 0; i < portList.length; i++) {
    console.log(i + " " + portList[i]);
  }
}
