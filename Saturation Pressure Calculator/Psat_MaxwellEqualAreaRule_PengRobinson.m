function P = Van_der_waals(T)
R = 8.314e-5;
T_c = 562.1; % Kelvin
P_c = 48.94; % Bar
a = 27/64*((R*T_c)^2)/(P_c);
b = R*T_c/(8*P_c);

P = [];
for v = b:.00001:(1000*b)
    P = [P (R*T)/(v-b) - a/v^2];

end
