// inspired by Daniel Shiffman's code with texrt video
let libra = ['happy', 'rainbow', 'unicorn', 'peace', 'sun'];
let words = [];
let occurrences = [];
let lang, speechRec;
let w;

//serial
let serial; // instance of the serialport library
// TODO: change this
let portName = '/dev/ttyACM0'; // fill in your serial port name here

function setup() {
    createCanvas(windowWidth, windowHeight);
    background(0);
    lang = 'en-US';
    speechRec = new p5.SpeechRec(lang, gotSpeech);
    let continuous = true;
    let interim = true;
    speechRec.start(continuous, interim); 

    //serial
   serial = new p5.SerialPort(document.location.hostname);
    // set callback functions for list and data events:
   serial.on('list', printList);
   serial.on('data', serialEvent);
    // open the serial port:
   serial.open(portName);
  }

let prevSec = 0;

function gotSpeech() {
    if (speechRec.resultValue) {
      //createP(speechRec.resultString);
      w = speechRec.resultString;
      if(w !== words[words.length-1]){
      words.push(w);
        for (let  a = 0,  b = words.length; a < b; a++) {
          occurrences[words[a]] = (occurrences[words[a]] || 0) + 1;
          }
      }
      for (let i = 0; i < libra.length; i++){
      if (words[words.length-1] == libra[i]){
      serial.write("y");
      noStroke();
      fill(0);
      rect(0, 0, width, height);
      fill(255);
      textSize(70);
      text(words[words.length-1], width/5, height/3);
      }

    }
    }
  }

function serialEvent() {
	// read a line of text in from the serial port:
	let data = serial.readStringUntil('\r\n');
	console.log(data);
	//send a byte to the microcontroller
	//to prompt it to respond with another reading:
}

function printList(portList){
	for(let i = 0; i <  portList.length; i++){
	console.log(i + ' ' + portList[i]);
}
}
