/*
 * File:   lab_12_p1.c
 * Author: frimponi
 *
 * Created on December 5, 2018, 2:13 PM
 */

#include "ece212.h"

int main() {

    int left_sensor;
    int right_sensor;

    int curr_rval ;
    int curr_lval ;

    ece212_lafbot_setup() ;

    // Since the robot start on the white line, the sensor would have a value of
    // zero
    //left_sensor = analogRead(LEFT_SENSOR);
   //right_sensor = analogRead(RIGHT_SENSOR);

    left_sensor = 0x12C;
   right_sensor = 0x12C;


    while(1) {

        //Calculate current value of sensor
        curr_rval = analogRead(RIGHT_SENSOR);
        curr_lval = analogRead(LEFT_SENSOR);

        if ( curr_lval <= left_sensor && curr_rval <= right_sensor){
            // Continue to move the robot forward
            RBACK = 0;
            RFORWARD = 0xFFFF;
            LBACK = 0;
            LFORWARD= 0xFFFF;

        }

        //Turning Left
        else if (curr_lval > left_sensor && curr_rval <= right_sensor){
            // Turning Right
            RBACK = 0;
            RFORWARD = 0xFFFF;
            LBACK = 0;
            LFORWARD= 0x2FFF;
        }


        // Turning Right
        else if (curr_rval > right_sensor && curr_lval <= left_sensor){
                  // Turning Left
            RBACK = 0;
            RFORWARD = 0x2FFF;
            LBACK = 0;
            LFORWARD= 0xFFFF;
        }


        delayms(5) ;





    }

    return (EXIT_SUCCESS);
}

