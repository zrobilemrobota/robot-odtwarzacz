

// set pin numbers
const int buttonPin = 15;     // the number of button / contact sensor pin
const int ledPin =  2;       // the number of the LED pin on your board

// variables
int buttonState = 0; // variable for storing the pushbutton status
boolean soundplayed = false; // variable for storing if the sound was played

#include <SoftwareSerial.h>
#include <DFMiniMp3.h>


// obligatory class for DfMiniMp3 library
class Mp3Notify
{
public:
  static void PrintlnSourceAction(DfMp3_PlaySources source, const char* action)
  {
    if (source & DfMp3_PlaySources_Sd) 
    {
        Serial.print("SD Card, ");
    }
    if (source & DfMp3_PlaySources_Usb) 
    {
        Serial.print("USB Disk, ");
    }
    if (source & DfMp3_PlaySources_Flash) 
    {
        Serial.print("Flash, ");
    }
    Serial.println(action);
  }
  static void OnError(uint16_t errorCode)
  {
    // see DfMp3_Error for code meaning
    Serial.println();
    Serial.print("Com Error ");
    Serial.println(errorCode);
  }
  static void OnPlayFinished(DfMp3_PlaySources source, uint16_t track)
  {
    Serial.print("Play finished for #");
    Serial.println(track);  
  }
  static void OnPlaySourceOnline(DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "online");
  }
  static void OnPlaySourceInserted(DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "inserted");
  }
  static void OnPlaySourceRemoved(DfMp3_PlaySources source)
  {
    PrintlnSourceAction(source, "removed");
  }
};

SoftwareSerial secondarySerial(D1, D2); // RX, TX pin declaration
DFMiniMp3<SoftwareSerial, Mp3Notify> mp3(secondarySerial); // object creation

void setup() {
  Serial.begin(9600);

  Serial.println("initializing...");
  
  mp3.begin();
  mp3.reset(); 
  
  // show some properties and set the volume
  uint16_t volume = mp3.getVolume();
  Serial.print("volume ");
  Serial.println(volume);
  mp3.setVolume(24);
 
  
  Serial.println("starting...");
  mp3.setRepeatPlayCurrentTrack(false);
  mp3.setRepeatPlayAllInRoot(false);

 
  pinMode(buttonPin, INPUT);  // initialize the pushbutton pin as an input
  pinMode(ledPin, OUTPUT); // initialize the LED pin as an output
}

void loop() {

  buttonState = digitalRead(buttonPin);   // read the state of the pushbutton value
  Serial.println(buttonState); // print to serial state of a button

  // playing logic 
  if (buttonState == LOW) {
    if(soundplayed == false){
      mp3.playMp3FolderTrack(1);
      soundplayed = true; 
    }
    digitalWrite(LED_BUILTIN, HIGH);

    

    
  } else {
    soundplayed = false;
    mp3.stop();
    // turn LED off
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  mp3.loop();
}
