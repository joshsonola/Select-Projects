function P = plot_Peng_project(T,T_c,P_c,w)
for i=1:length(T)
    [P,b] = Peng_Robinson(T(i),T_c,P_c,w); % Solve for Pressure
    % using Peng_Robinson EOS
    v = b:.00001:(1000*b); % Redefine v to be the same v used in the Peng
    % Robinson EOS
    figure;
    plot(v,P); % Plot the Peng Robinson EOS for this given Temperature
    xlabel('Specific Volume (m^3/mol)', 'FontSize', 20); % x-axis label
    ylabel('Pressure (bar)','FontSize', 20); % y-axis label
    str = sprintf('Peng Robinson EOS for T = %f',T);
    title(str,'FontSize', 20); % Title
    axis([0,500*b,-200,100]);
end
end