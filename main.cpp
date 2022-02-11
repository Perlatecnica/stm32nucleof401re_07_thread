/* Copyright (c) 2022 Perlatecnica
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/****************************************************
*           RAPID PROTOTYPING WITH NUCLEO           *
* Example Code 07: Thread usage                     *
* Author: Mauro D'Angelo                            *
* Organization: Perlatecnica APS ETS 				*
*****************************************************/

#include "mbed.h"

// It declares a thread
Thread thread;

// mybutton variable's type is DigitalIn. It points to the user button available on the board
DigitalIn mybutton(BUTTON1);

DigitalOut myled(LED1);

// It is the interval
int delay = 0;

// Implementa la funzione associata al Thread
// Quando viene premuto il pulsante (mybutton == 0) 
// viene impostato il nuovo valore della variabile delay

// This is the function started as thread
void button_thread(void) {
    while(true) {
        if (mybutton == 0) { // Button is pressed
            if (delay == 1000)
                delay = 200; // 200 ms
            else
                delay = 1000; // 1 sec
         }// if button
        wait_us(500*1000);
    }
}

int main() {  
    // Threads start here. Here it is attached the function
    thread.start(button_thread);
    
    // Blinking led
    while(true) {
        myled = !myled;
        wait_us(delay*1000);
    }
}
