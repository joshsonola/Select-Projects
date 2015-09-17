%% Import Data into Dictionary and Display Keys
% Import Data for T_c, P_c, w, formula, and name
Peng_spreadsheet = importdata('Peng_Robinson_Data.xlsx');
n = length(Peng_spreadsheet.textdata);

Formula = char(Peng_spreadsheet.textdata(2:n,1)); % Capture the formulas from the spreadsheet
% by excluding the top row of the data
Name = char(Peng_spreadsheet.textdata(2:n,2)); % Capture the names from the spreadsheet
% by excluding the top row of the data
T_c = Peng_spreadsheet.data(:,1);
P_c = Peng_spreadsheet.data(:,2);
w = Peng_spreadsheet.data(:,3);
keySet = {}; % Initialize the keys of the Dictionary
valueSet = {}; % Initialize the values of the Dictionary
for i=1:length(T_c)
    keySet = [keySet {Name(i,:)}]; % Append the names of the molecules onto the keys
    valueSet = [valueSet {[T_c(i),P_c(i),w(i)]}]; % Append the data for each molecule into the values
end

Map = containers.Map(keySet,valueSet); % Construct the dictionary
display(keys(Map)); % Display all of the possible species
%% Input The Species and Display/Store Its Information
species = input('What species do you want information for? (Species shown above) (Do not enter as a string) ','s'); % Convert the user input after the first prompt into a string variable
n = (22-length(species)); % Convert the variable into the value that's in the dictionary
% (22 total character spaces)
species_original = species; % Species without spaces
for i=1:n
    species = strcat(species,{' '});
end
species = char(species);
Peng_values = values(Map,{species}); % Retrieve values for the given species
disp('    T_c        P_c        w')
disp(cell2mat(Peng_values)); % Display the values of T_c, P_c, and w for 
% the chosen species
Peng_values = cell2mat(Peng_values); % Store the values for T_c, P_c, and w
T_c = Peng_values(1);
P_c = Peng_values(2);
w = Peng_values(3);

%% Pick which option to run and run the option
prompt3a = 'a) Plot the Peng Robinson Equation of State at different temperatures';
prompt3b = 'b) Plot the Peng Robinson Equation of State at different temperatures with the Saturation Pressure';
prompt3c = 'c) Plot the Saturation Curve of the Species';
prompt3d = 'd) Plot the Saturation Curve and the Spinodal Curve of the Species';
prompt3e = 'e) Calculate the Saturation Pressure of the Species at different temperatures';
% Display all of the options available
disp(prompt3a);
disp(prompt3b);
disp(prompt3c);
disp(prompt3d);
disp(prompt3e);
finish = 0; % Initialize while loop variable

while finish == 0
% Ask the user for which option to proceed with
answer = input('What would you like to do with the following species? ','s'); % Input the answer to the prompted question as a string
if answer == 'a'
    prompt4 = 'What temperature(s) do you want the Peng Robinson EOS at? (Input a vector for multiple T values) ';
    T = input(prompt4); % Input T Values
    plot_Peng_project(T,T_c,P_c,w); % Plot the Peng Robinson EOS at these different T's
    finish = 1; % End the while loop
elseif answer == 'b'
    P_sat = [];
    prompt4 = 'What temperature(s) do you want the Peng Robinson EOS at? (Input a vector for multiple T values) ';
    T = input(prompt4); % Input the T Values
    for i=1:length(T) % Solve for the saturation pressure at each temperature
        P_sat = [P_sat P_sat_solver(T(i),T_c,P_c,w)];
    end
    plot_Peng_sat_project(T,T_c,P_c,w,P_sat); % Plot the Peng Robinson EOS
    % along with the Saturation Pressure at given Temperatures. 
    display(P_sat)
    finish = 1; % End the while loop
elseif answer == 'c'
    R = 8.314e-5;
    T = .3*T_c:.01*T_c:.99*T_c;
    P_sat = [];
    v_sat = [];
    % Solve for the saturation volumes and saturation Pressures from T =
    % .3*T_c to .99*T_c. 
    for i=1:length(T)
        P_sat = [P_sat; P_sat_solver(T(i),T_c,P_c,w)]; % Calculate and ammend the P_sat 
        [v_lower, v_upper] = v_sat_solver(T(i),T_c,P_c,w,P_sat(i)); % Calculate the saturation volumes
        v_sat = [v_sat ;v_lower,v_upper];
    end
    figure;
    plot(v_sat,P_sat)
    legend('Saturation Curve Liquid','Saturation Curve Vapor');
    xlabel('Specific Volume (m^3/mol)', 'FontSize', 20); % x-axis label
    ylabel('Pressure (bar)','FontSize', 20); % y-axis label
    str = sprintf('Saturation Curve for %s from Peng Robison EOS',species_original);
    title(str,'FontSize', 20); % Title
    axis([0,.025,0,P_c]);
    finish = 1; % End the while loop
elseif answer == 'd'
    R = 8.314e-5;
    T = .3*T_c:.01*T_c:1*.99*T_c;
    P_sat = [];
    v_sat = [];
    v_spin = [];
    P_spin = [];
    % Solve for the saturation volumes and saturation Pressures from T =
    % .3*T_c to .99*T_c. Also solve for the spinodal curve for T = .3*T_c
    % to .99*T_c. 
    for i=1:length(T)
        P_sat = [P_sat; P_sat_solver(T(i),T_c,P_c,w)];
        [P_min, P_max,v_min, v_max] = v_spin_solver(T(i),T_c,P_c,w);
        v_spin = [v_spin; v_min v_max];
        P_spin = [P_spin ; P_min, P_max];
        [v_lower, v_upper] = v_sat_solver(T(i),T_c,P_c,w,P_sat(i));
        v_sat = [v_sat ;v_lower,v_upper];
        
    end
    R = 8.314e-5; % m^3*bar*K^-1*mol^-1
    b = .07780*R*T_c/(P_c);
    v = b:.00001:(1000*b);
    v_spin = v(v_spin); % Convert the indices to the actual volume values
    
    figure;
    hold on
    plot(v_sat,P_sat);
    plot(v_spin(:,1), P_spin(:,1));
    plot(v_spin(:,2), P_spin(:,2));
    legend('Saturation Curve Liquid','Saturation Curve Vapor','Spinodal Curve Liquid','Spinodal Curve Vapor');
    xlabel('Specific Volume (m^3/mol)', 'FontSize', 20); % x-axis label
    ylabel('Pressure (bar)','FontSize', 20); % y-axis label
    str = sprintf('Spinodal and Saturation Curve for %s from Peng Robison EOS',species_original);
    title(str,'FontSize', 20); % Title
    axis([0,.025,0,P_c]);
    finish = 1; % End the while loop
elseif answer == 'e'
    P_sat = [];
    prompt4 = 'What temperature(s) do you want Saturation Pressure of? (Input a vector for multiple T values) ';
    T = input(prompt4); % Input T Values
    for i=1:length(T) % Solve for P_sat at different temperatures
        P_sat = [P_sat P_sat_solver(T(i),T_c,P_c,w)];
    end
    display(P_sat)
    finish = 1; % End the while loop
elseif strcmp(answer,'exit')
    finish = 1; % End the while loop
else
    display('Please pick a valid option. (Case Sensitive) (Do not enter a string). Type exit to exit.');
end
end

    

