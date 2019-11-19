// inspired by Daniel Shiffman's code with texrt video
let libra = ['happy', 'rainbow', 'unicorn', 'peace', 'sun', 'support'];
let words = [];
let occurrences = [];
let lang, speechRec;
let w;

let serial; // variable to hold an instance of the serialport library
let portName = '/dev/ttyACM0'; // fill in your serial port name here
let inData; // for incoming serial data
let sensors;

//serial
let serial; // instance of the serialport library
let portName = '/dev/ttyS0'; // fill in your serial port name here

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
    serial.open(portName);
    serial.on('data', serialEvent);
    serial.on('connected', serverConnected);
    serial.on('error', serialError);
  }
  
function gotSpeech() {
    if (speechRec.resultValue) {
      //createP(speechRec.resultString);
      w = speechRec.resultString;
      if(w !== words[words.length-1]){
      words.push(w);
      serial.write("H");
        for (let  a = 0,  b = words.length; a < b; a++) {
          occurrences[words[a]] = (occurrences[words[a]] || 0) + 1;
          }
      }else{
        Serial.write("L");
      }
      for (let i = 0; i < libra.length; i++){
      if (words[words.length-1] == libra[i]){
      noStroke();
      fill(0);
      rect(0, 0, width, height);
      fill(255);
      textSize(70);
      text(words[words.length-1], width/5, height/3);
      textSize(32);
      text('temperature : 70, humidity: 50%',width/5, 3*height/4);
      }

    }
    }
  }

  function printList(portList) {
    for (let i = 0; i < portList.length; i++) {
      console.log(i + " " + portList[i]);
    }
  }
