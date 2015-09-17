function [P_min, P_max,v_min, v_max] = v_spin_solver(T,T_c,P_c,w)
% Find local minima'
P = Peng_Robinson(T,T_c,P_c,w);
[P_min, v_min] = findpeaks(-P);
P_min = -P_min;
if isempty(P_min) % If only a global minima exists
    [P_min, v_min] = min(P);
end
P_min = max(P_min); % So we don't get negative infinity
v_min = max(v_min);
% Find local maxima
[P_max, v_max] = findpeaks(P);
if isempty(P_max) % If only a global maxima exists
    [P_max, v_max] = max(P);
end
P_max = min(P_max); % So we don't get infinity
v_max = max(v_max);
end