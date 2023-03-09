#include <kipr/wombat.h>
#include <functions.h>
#include <consts.h>
#include <UI.h>
#include <GCER.h>
#include <timer.h>

int dspd = 950;
int tspd = 550;
int sqspd = 500;

int god_start(){
	//while(startup){button_press(); msleep(50);}
    slow_servo(arm,arm_min+630,1);
    slow_servo(claw,claw_max,1);
    reset_timer(1);
    return green();
    //return green_two();
}
int green(){   
    //perfect code
    in_turn(-28,tspd);
    slow_servo(arm,arm_min+270,1);
    in_drive(dspd,7);
    slow_servo(claw,claw_min,2);
    msleep(100);
    in_turn(28,tspd);
    square_up(2,sqspd);
    in_drive(-1*dspd,4);
    
    slow_servo(arm,arm_min + 800,2);
    
    in_turn(90,tspd);
    square_up(2,sqspd);
    
    slow_servo(arm,arm_min+600,2);
    msleep(100);
    
    
    in_turn(40,tspd+50);
    slow_servo(claw,claw_max,2);
    in_turn(-40,tspd+50);
     slow_servo(arm,arm_max-500,1);
    msleep(100);
    square_up(2,sqspd);

	return grab_cube();
}
int grab_cube(){
	in_drive(dspd,21);
    stop_it();
    //while(buffer(fET) < 1500){move(80,100); if(buffer(fET) >= 1500){stop_it();}}
    in_turn(23,tspd);
    if(buffer(fET) < 2100){
    	find_cube();
    }
    slow_servo(arm,arm_min+500,1);
    in_drive(dspd,4.1);
    slow_servo(claw,claw_min,2);
    return deliver_cube();
}
int deliver_cube(){
    in_drive(-1*dspd,5);
    in_turn(-20,tspd);
    slow_servo(arm,arm_max-400,1);
    in_drive(-1*dspd,17);
    square_up(2,-1*sqspd);
    in_drive(-1*dspd,14);
    square_up(2,sqspd);
    in_turn(-90,tspd);
    in_drive(-1*dspd,10);
    in_drive(dspd,2);
    slow_servo(arm,arm_min+400,1);
    in_turn(25,tspd);
    slow_servo(claw,claw_max,2);
	return green_two();
}
int green_two(){
    //
     in_drive(-1*dspd,4);
    slow_servo(arm,arm_max-400,1);
    in_drive(dspd,3);
    in_turn(80,tspd);
    square_up(2,sqspd);
    square_up(2,sqspd);
    in_drive(dspd,10);
    square_up(2,sqspd);
    in_turn(-90,tspd);
    in_drive(-1*dspd,8); //5
    //
    
    in_turn(30,tspd);
    slow_servo(arm,arm_min+100,2);
    in_drive(dspd,6);
    slow_servo(claw,claw_min,2);
    in_turn(-25,tspd);
    in_drive(dspd,2);
    square_up(2,sqspd);
    
    in_drive(dspd,6);
    in_turn(120,tspd+50);
    slow_servo(arm,arm_min+500,2);
    in_drive(-1*dspd,3);
    in_turn(60,tspd);
    in_drive(-1*dspd,4);
    square_up(2,-1*sqspd);
    in_turn(50,tspd);
    //in_drive(dspd,3);
    slow_servo(claw,claw_max,2);
    slow_servo(arm,arm_min+500,1);
    in_drive(-1*dspd,1.5);
    in_turn(-45,tspd);
    square_up(2,sqspd);
    
	return stacks();
}
int stacks(){
    //in_drive(dspd,1);
    in_turn(-90,tspd);
    slow_servo(arm,arm_min+600,1);
    in_drive(-1*dspd,11);
    square_up(2,-1*sqspd);
    stop_it();
    in_drive(dspd,14);
    slow_servo(arm,arm_min+500,1);
    in_turn(33,tspd);
    in_drive(dspd,3.7); 
    slow_servo(claw,claw_min,2);
    slow_servo(arm,arm_min+600,1);
    in_drive(dspd,4);
    in_turn(65,tspd);
    square_up(2,-1*sqspd);
    in_drive(dspd,6);
    slow_servo(claw,claw_max,2);
    slow_servo(arm,arm_min+600,1);
    in_turn(-95,tspd);
    in_drive(-1*dspd,6);
    slow_servo(arm,arm_min+100,1);
    in_drive(dspd,6);
    slow_servo(claw,claw_min+200,2);
    msleep(300);
    in_turn(-200,tspd);
    
    /*
    slow_servo(arm,arm_min+495,1);
    in_drive(dspd,6);
    slow_servo(claw,claw_min,2);
    in_turn(-40,tspd);
    slow_servo(arm,arm_min+200,1);
    in_drive(dspd,2);
    in_turn(70,tspd);
    in_drive(dspd,2);
    slow_servo(arm,arm_min+400,1);
    in_turn(-210,tspd);
    */
	return end();
}
int end(){
    console_clear();
    printf("\n%d time\n",timer(1));
    //in_drive(-400,2);
    //msleep(2000);
    return 0;
}