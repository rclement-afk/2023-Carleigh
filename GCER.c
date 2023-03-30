#include <kipr/wombat.h>
#include <functions.h>
#include <consts.h>
#include <UI.h>
#include <GCER.h>
#include <timer.h>

int dspd = 950;
int tspd = 600;
int sqspd = 550;

int god_start(){
	//while(startup){button_press(); msleep(50);}
    slow_servo(arm,arm_min+630,1);
    slow_servo(claw,claw_max,1);
    reset_claw();
    //to_pos(mclaw,mclaw_min);
    reset_arc();
    reset_timer(1);
    //return green();
    return green_two();
}
int green(){   
    //perfect code
    in_turn(-28,tspd);
    slow_servo(arm,arm_min+300,1);
    in_drive(dspd,7);
    slow_servo(claw,claw_min,2);
    msleep(100);
    in_turn(28,tspd);
    square_up(2,sqspd);
    in_drive(-1*dspd,3.5);
    
    slow_servo(arm,arm_min + 800,2);
    
    in_turn(90,tspd);
    square_up(2,sqspd);
    
    slow_servo(arm,arm_min+600,2);
    msleep(100);
    
    
    in_turn(40,tspd+100);
    slow_servo(claw,claw_max,2);
    in_turn(-40,tspd+100);
     slow_servo(arm,arm_max-500,1);
    msleep(100);
    square_up(2,sqspd);

	return grab_cube();
}
int grab_cube(){
	in_drive(dspd,22);
    stop_it();
    //while(buffer(fET) < 1500){move(80,100); if(buffer(fET) >= 1500){stop_it();}}
    in_turn(24,tspd);
    if(buffer(fET) < 2100){
    	find_cube();
    }
    slow_servo(arm,arm_min+500,1);
    in_drive(dspd,4.5);
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
    in_turn(-90,tspd+50);
    in_drive(-1*dspd-50,10);
    in_drive(dspd,2);
    slow_servo(arm,arm_min+400,1);
    in_turn(25,tspd);
    slow_servo(claw,claw_max,2);
	return green_two();
}
int green_two(){
    /*
     in_drive(-1*dspd-50,4);
    slow_servo(arm,arm_max-400,1);
    in_drive(dspd,3);
    in_turn(80,tspd);
    square_up(2,sqspd);
    square_up(2,sqspd);
    in_drive(dspd,10);
    square_up(2,sqspd);
    in_turn(-90,tspd);
    in_drive(-1*dspd,8); //5
    */
    
    in_turn(30,tspd);
    slow_servo(arm,arm_min+350,2);
    in_drive(dspd,6);
    slow_servo(claw,claw_min,2);
    in_turn(-25,tspd);
    in_drive(dspd,2);
    square_up(2,sqspd);
    square_up(2,sqspd);
    
    in_drive(dspd,6);
    
    in_turn(120,tspd+100);
    slow_servo(arm,arm_min+590,2);
    in_drive(-1*dspd,3);
    in_turn(55,tspd);
    in_drive(-1*dspd,4);
    square_up(2,-1*sqspd);
     square_up(2,-1*sqspd);
    in_turn(50,tspd);
    slow_servo(claw,claw_max,2);
    slow_servo(arm,arm_min+500,1);
    
    in_drive(-1*dspd,2);
    in_turn(-40,tspd);
    square_up(2,sqspd);
    
    /*
    in_drive(-1*dspd,6);
    slow_servo(arm,arm_min+400,1);
    in_turn(-120,tspd);
    in_drive(-1*dspd,13.5);
    square_up(2,-1*sqspd);
    in_drive(dspd,6);
    slow_servo(arm,arm_min+700,1);
    in_turn(60,tspd+50);
     in_drive(-1*dspd,6);
      in_turn(60,tspd+50);
      */
	return botgal();
}
int stacks(){
    //in_drive(dspd,1);
    in_turn(-83,tspd);
    slow_servo(arm,arm_min+750,1);
    in_drive(-1*dspd,11);
    square_up(2,-1*sqspd);
      square_up(2,-1*sqspd);
    stop_it();
    in_drive(dspd,17.5);
    in_turn(28,tspd);
    slow_servo(arm,arm_min+570,1);
    stop_it();
    in_drive(400,1); 
    slow_servo(claw,claw_min,2);
    slow_servo(arm,arm_min+600,1);
    in_drive(dspd,3);
    slow_servo(arm,arm_min+530,1);
    in_turn(65,tspd);
    square_up(2,-1*sqspd);
    in_drive(dspd,6);
    slow_servo(claw,claw_max,2);
    slow_servo(arm,arm_min+550,1);
    in_drive(-1*dspd,5);
    square_up(2,-1*sqspd);
    in_drive(dspd,7);
    in_turn(-90,tspd);
    in_drive(-1*dspd,6);
    slow_servo(arm,arm_min+300,1);
    in_drive(dspd,5);
    slow_servo(claw,claw_min+150,1);
    msleep(300);
    in_turn(-200,tspd+100);
    in_drive(dspd,8);
     slow_servo(claw,claw_max,2);
    in_drive(-1*dspd,2);
     slow_servo(arm,arm_min+600,1);
    in_turn(15,tspd);
    square_up(2,sqspd);
    square_up(2,sqspd);

	return botgal();
}
int botgal(){
    in_drive(-1*dspd,2);
    to_pos(marm,marm_up);
    in_drive(-1*dspd,13);
    to_pos(mclaw,mclaw_min);
    reset_arc();
    to_pos(marm,marm_cant);
	return noodles();
}
int noodles(){
	return end();
}
int end(){
    console_clear();
    printf("\n%d time\n",timer(1));
    //in_drive(-400,2);
    //msleep(2000);
    return 0;
}