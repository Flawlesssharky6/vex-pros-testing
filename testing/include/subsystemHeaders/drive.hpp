#pragma once

//helper functions
void setDrive(int left, int right);

void setDriveDriver(int left, int right);

void resetDriveEncoders();

double avgDriveEncoderValue();

//driver control functions
void setDriveMotors();

//autonomous functions
void translate(double units, int voltage);

void rotateClockWise(int degrees, int velocity);

