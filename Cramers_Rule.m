%Cramer's Rule
m1 = 2;
m2 = 1;
m3 = 1;
g = 10;
kk = 2; %setting constants

K =[3*kk, -2*kk, 0; -2*kk, 3*kk, -kk; 0, -kk, kk];
W =[m1*g; m2*g; m3*g]; %making initial arrays

detK= (K(1) * K(5) * K(9)) + (K(2) * K(6) * K(7)) + (K(3) * K(4) * K(8)) - (K(3) * K(5) * K(7)) - (K(2) * K(4) * K(9)) - (K(1) * K(6) * K(8));
detx = (W(1) * K(5) * K(9)) + (K(2) * K(6) * W(3)) + (K(3) * W(2) * K(8)) - (K(3) * K(5) * W(3)) - (K(2) * W(2) * K(9)) - (W(1) * K(6) * K(8));
dety = (K(1) * W(2) * K(9)) + (W(1) * K(6) * K(7)) + (K(3) * K(4) * W(3)) - (K(3) * W(2) * K(7)) - (W(1) * K(4) * K(9)) - (K(1) * K(6) * W(3));
detz = (K(1) * K(5) * W(3)) + (K(2) * W(2) * K(7)) + (W(1) * K(4) * K(8)) - (W(1) * K(5) * K(7)) - (K(2) * K(4) * W(3)) - (K(1) * W(2) * K(8));

x = detx/detK;
y = dety/detK;
z = detz/detK; %Cramer's Rule

f1 = (2 * kk *( y - x)) + (m1 * g) - (kk * x);
f2 = (kk * (z-y)) +(m2*g)-(2 * kk * (y-x));
f3 = (m3 * g) - (kk * (z - y));

fprintf('The force on mass 1 is: %f\n.',f1);
fprintf('The force on mass 2 is: %f\n.',f2);
fprintf('The force on mass 3 is: %f\n.',f3);
fprintf('The displacement of mass 1 is: %f\n.',x);
fprintf('The displacement of mass 2 is: %f\n.',y);
fprintf('The displacement of mass 3 is: %f\n.',z);