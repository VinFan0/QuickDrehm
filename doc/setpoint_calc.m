clc
clear
% FieldMarker Setpoint Calculator
% Input from drone peripherals
%   cur_long:   (x axis) current longitude (degrees)
%   cur_lat:    (y axis) current latitude (degrees)
%   orient:     compass orientation (degrees)
%   dest_long:  destination longitude (degrees)
%   dest_lat:   destination latitude (degrees)

cur_long = 0;
cur_lat = 0;
orient = 270;
dest_long = -5;
dest_lat = -5;

% Output
%   roll_command:   amount of roll for motor commands
%   pitch_command:  amount of pitch for motor commands
roll_command = 0;
pitch_command = 0;


% Calculate latitude and longitude displacements
delta_long = dest_long-cur_long;
delta_lat = dest_lat-cur_lat;

% Rotate destination point
% Rotating the destination point by the orientation 
% amount brings the drones frame of reference in
% alignment with the x and y axis, where x represents
% roll/longitude and y is pitch or latitude
theta = deg2rad(orient);
theta_read = theta/pi;

% So now instead of the destination being "this many
% units" north/south and "this many units" east/west,
% the destination is "this far" forward/backward, and
% "this far" right/left
x_prime = delta_long*cos(theta)-delta_lat*sin(theta)
y_prime = delta_long*sin(theta)+delta_lat*cos(theta)

% Scale the prime values for motor commands