function plot_Peng_sat_project(T,T_c,P_c,w,P_sat)
for i=1:length(T)
    [P,b] = Peng_Robinson(T(i),T_c,P_c,w); % Solve for Pressure from Peng
    % Robinson EOS
    v = b:.00001:(1000*b); % Create the same vector that was used in the 
    % Peng Robinson EOS solver
    figure;
    hold on
    plot(v,P); % Plot the Peng Robinson EOS for this given Temperature
    plot([0,500*b],[P_sat(i),P_sat(i)]); % Plot the saturation Pressure
    xlabel('Specific Volume (m^3/mol)', 'FontSize', 20); % x-axis label
    ylabel('Pressure (bar)','FontSize', 20); % y-axis label
    str = sprintf('Peng Robinson EOS with Saturation Pressure for T = %f',T);
    title(str,'FontSize', 20); % Title
    axis([0,500*b,-200,100]);
end
end
