function P_sat = P_sat_solver(T,T_c,P_c,w)
f = @(P)my_peng_integral(T,P,T_c,P_c,w);
[P_min, P_max] = v_spin_solver(T,T_c,P_c,w);
P = mean([max(0,P_min),P_max]); % Set the guess as the average between the 
% local minimum and local maximum. If the local minimum is less than 0, use
% 0 because our saturation pressure can not be negative.
P_sat = lsqnonlin(f,P,0,1000,optimset('TolX',1e-15,'display','off')); % Solve for P_sat
end
