function [P,b] = Peng_Robinson(T,T_c,P_c,w)
R = 8.314e-5; % m^3*bar*K^-1*mol^-1
a = .45724*((R*T_c)^2)/(P_c);
b = .07780*R*T_c/(P_c);
k = .37464 + 1.5423*w - .26992*w^2;
T_r = T/T_c;
alpha_T = (1 + k*(1-sqrt(T_r)))^2;

P = [];
for v = b:.00001:(1000*b) % Iterate through specific volumes 
    P = [P (R*T)/(v-b) - (a*alpha_T)/(v*(v+b) + b*(v-b))]; % Solve for P 
    % and ammend this onto our P vector
end
end

