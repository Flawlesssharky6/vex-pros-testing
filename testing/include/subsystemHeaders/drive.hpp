#pragma once

//helper functions
void setDrive(int left, int right);

void resetDriveEncoders();

double avgDriveEncoderValue();

//driver control functions
void setDriveMotors();

//autonomous functions
void translate(int units, int voltage);

void rotate(int degrees, int voltage);