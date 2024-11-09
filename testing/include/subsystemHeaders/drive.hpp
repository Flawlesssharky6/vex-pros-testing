#pragma once

//helper functions
void setDriveVelocity(int left, int right);

void setDrive(int left, int right);

void resetDriveEncoders();

double avgDriveEncoderValue();

//driver control functions
void setDriveMotors();

//autonomous functions
void velocityTranslate(int units, int velocity);

void translate(int units, int voltage);

void rotate(int degrees, int voltage);

void rotateClockWise(int degrees, int velocity);

void timedTurn(double millisec);

void timedTurnCC(double millisec);