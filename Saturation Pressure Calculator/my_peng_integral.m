function I = my_peng_integral(T,P_sat,T_c,P_c,w)
R = 8.314e-5;
a = .45724*((R*T_c)^2)/(P_c);
b = .07780*R*T_c/(P_c);
k = .37464 + 1.5423*w - .26992*w^2;
T_r = T/T_c;
alpha_T = (1 + k*(1-sqrt(T_r)))^2;

syms v
F1 = (R*T)/(v-b) - (a*alpha_T)/(v*(v+b) + b*(v-b));
F = @(v)(R*T)/(v-b) - (a*alpha_T)/(v*(v+b) + b*(v-b)) - P_sat;
solutions = vpasolve(F1 == P_sat,v,[0,50]); % Solve for the x intersections 
% of the Peng Robinson EOS and the Saturation Pressure
if length(solutions) == 2 % Saturation Pressure Intersects Twice
    v_lower = double(solutions(1));
    v_upper = double(solutions(2));
    I = integral(F, v_lower,v_upper,'ArrayValued',true);
elseif length(solutions)== 1 % Saturation Pressure Intersects Once
    I = -1000; % Non zero value
else
    v_lower = double(solutions(1));
    v_upper = double(solutions(3));
    I = integral(F, v_lower,v_upper,'ArrayValued',true);
end