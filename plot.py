# plot.py (Execute with python3)
# Programming project 2018 ISP - Segway
# (c) Matthias Braendel, 2019

# Libraries
import matplotlib.patches as patches
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec
import numpy as np
import sys
print("Libraries imported.");

# Opening file
#    segway.txt
# And reading entities: t,x,a,F,T 
# Variables
t01 = []; x01 = []; a01 = []; F01 = []; T01 = [];
if(1):  
  # Opening file
  F_inp = open("segway.txt","r");
  # Reading variables
  while True:
    line = F_inp.readline();
    # If end of file reached
    if(line == ""):
      break;
    inp = line.split(" ");
    t01.append(float(inp[0]));
    x01.append(float(inp[1]));
    a01.append(float(inp[2]));
    F01.append(float(inp[3]));
    T01.append(float(inp[4]));
  # Closing file
  F_inp.close();
  print("segway.txt read.");

# Eval read data
if(len(t01) > 0):
  framerate = t01[1]-t01[0];
  t_min = np.amin(t01); 
  t_max = np.amax(t01);
else:
  print("No plot selected.");
  print("Program ends.");
  sys.exit();
framerate = int(1/framerate);
print('Calculated framerate ', framerate, '.');
print('Time interval [', t_min, ',', t_max, '].');

# Plot picture
f01 = plt.figure();  
f01.set_size_inches(8.4,4.8);
if(1):
  # Dummy variables
  valt = t01; valX = x01; valA = a01; valF = F01; valT = T01;
  gs = gridspec.GridSpec(4,1, height_ratios=[2,2,1,1]);
  # Create subplot for x
  axx = plt.subplot(gs[0]);
  # Plot x
  axx.plot(valt,valX,'r-'); 
  # Dummy variable
  val=valX;
  # Setting parameter
  axx.set_xlim([valt[0], valt[len(valt)-1]]);
  if(np.amin(val) != np.amax(val)):
    axx.set_ylim([np.amin(val)-0.1*(np.amax(val)-np.amin(val)), np.amax(val)+0.1*(np.amax(val)-np.amin(val))]);   
  else:
    axx.set_ylim([np.amin(val)-1, np.amax(val)+1]);
  axx.set_ylabel('x', fontweight='bold', Rotation=0);
  axx.set(xticklabels=[]);
  axx.set_title('Linear model with control', fontsize=14, fontweight='bold');
  # Create subplot for a
  axa = plt.subplot(gs[1]);
  # Plot a
  axa.plot(valt,[i/(np.pi/180) for i in valA],'r-'); 
  # Dummy variable
  val=[i/(np.pi/180) for i in valA];
  # Setting parameter
  axa.set_xlim([valt[0], valt[len(valt)-1]]);
  if(np.amin(val) != np.amax(val)):
    axa.set_ylim([np.amin(val)-0.1*(np.amax(val)-np.amin(val)), np.amax(val)+0.1*(np.amax(val)-np.amin(val))]);   
  else:
    axa.set_ylim([np.amin(val)-1, np.amax(val)+1]);
  axa.set_ylabel('a', fontweight='bold', Rotation=0);
  axa.set(xticklabels=[]);
  axa.yaxis.set_ticks_position('right');
  axa.yaxis.set_label_position('right');
  # Create subplot for F
  axF = plt.subplot(gs[2]);
  # Plot F
  axF.plot(valt,valF,'r-'); 
  # Dummy Variable
  val=valF;
  # Setting parameter
  axF.set_xlim([valt[0], valt[len(valt)-1]]);
  if(np.amin(val) != np.amax(val)):
    axF.set_ylim([np.amin(val)-0.1*(np.amax(val)-np.amin(val)), np.amax(val)+0.1*(np.amax(val)-np.amin(val))]);   
  else:
    axF.set_ylim([np.amin(val)-1, np.amax(val)+1]);
  axF.set_ylabel('F', fontweight='bold', Rotation=0);
  axF.set(xticklabels=[]);
  # Create subplot for T
  axT = plt.subplot(gs[3]);
  # Plot T
  axT.plot(valt,valT,'r-'); 
  # Dummy variable
  val=valT;
  # Setting parameter
  axT.set_xlim([valt[0], valt[len(valt)-1]]);
  if(np.amin(val) != np.amax(val)):
    axT.set_ylim([np.amin(val)-0.1*(np.amax(val)-np.amin(val)), np.amax(val)+0.1*(np.amax(val)-np.amin(val))]);   
  else:
    axT.set_ylim([np.amin(val)-1, np.amax(val)+1]);
  axT.set_ylabel('T', fontweight='bold', Rotation=0);
  axT.yaxis.set_ticks_position('right');
  axT.yaxis.set_label_position('right');
  # Position of subplots
  pT = axT.get_position(); p = pT;
  p = p.get_points(); t1 = p[0]; t2 = p[1]; 
  pT = [t1[0], t1[1], t2[0]-t1[0], t2[1]-t1[1]];
  pF = axF.get_position(); p = pF;
  p = p.get_points(); t1 = p[0]; t2 = p[1]; 
  pF = [t1[0], t1[1], t2[0]-t1[0], t2[1]-t1[1]];
  pa = axa.get_position(); p = pa;
  p = p.get_points(); t1 = p[0]; t2 = p[1]; 
  pa = [t1[0], t1[1], t2[0]-t1[0], t2[1]-t1[1]];
  px = axx.get_position(); p = px;
  p = p.get_points(); t1 = p[0]; t2 = p[1]; 
  px = [t1[0], t1[1], t2[0]-t1[0], t2[1]-t1[1]];
  pT[3] = pT[3]+1*(pF[1]-pT[1]-pT[3]);
  pF[3] = pF[3]+1*(pa[1]-pF[1]-pF[3]);
  pa[3] = pa[3]+0.5*(px[1]-pa[1]-pa[3]);
  px[1] = pa[1]+1*pa[3];
  axT.set_position(pT);
  axF.set_position(pF);
  axa.set_position(pa);
  axx.set_position(px);
  # Ausrichten der Axenschrittweite nach Innen
  axx.tick_params(direction='in', bottom=True, left=True, right=True, top=True);
  axa.tick_params(direction='in', bottom=True, left=True, right=True, top=True);
  axF.tick_params(direction='in', bottom=True, left=True, right=True, top=True);
  axT.tick_params(direction='in', bottom=True, left=True, right=True, top=True);
  print('Plot created.');
  f01.savefig('segway.pdf', format='pdf');
  f01.savefig('segway.png', format='png');
  print('Plot saved as *.pdf and *.png.');

