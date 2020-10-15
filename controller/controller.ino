/*
 Nathan Chay
 200403221
 CS 207
 Oct. 14, 2020 
*/

//  pins for buttons
const int BUTTON_PINS[8] = {4, 3, 5, 6, 13, 12, 11, 10};
const String BUTTON_NAMES[8] = {"Left", "Up", "Down", "Right", "Y", "X", "B", "A"};

//  last states of the buttons
int button_last_state[8] = {0, 0, 0, 0, 0, 0, 0, 0};

// current state of the button
int button_current_state = 0;

void setup()
{
  //  setting pins to input mode
  for (int i = 0; i < 7; i++)
  {
    pinMode(BUTTON_PINS[i], INPUT);
  }

  //  initialize serial output
  Serial.begin(9600);
}

void loop()
{
  //  looping through all buttons
  for (int i = 0; i < 7; i++)
  {
    //  getting current state of button
    button_current_state = digitalRead(BUTTON_PINS[i]);

    //  assume pull-up button configuration
    //  if the state goes from low to high, the button has been released
    if (button_last_state[i] == LOW && button_current_state == HIGH)
    {
      Serial.println(BUTTON_NAMES[i] + " released.");
      button_last_state[i] = HIGH;
    }
    //  if the state goes from high to low, the button has been pressed
    else if (button_last_state[i] == HIGH && button_current_state == LOW)
    {
      Serial.println(BUTTON_NAMES[i] + " pressed.");
      button_last_state[i] = LOW;
    }
  }
}
