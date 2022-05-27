# Iestyn Green & Jamie Mitchel OOSD Project 
Our project is a entertainment video game which includes graphics, animation and Audio; created with C++. 
Its development was based on meeting the needs of a University Project for Object-Oriented Software Development. 
Worked on extensively, the project relies on the SFML library to work. 

# Major Features
<ul><li>Navigable Main Menu</li>
  <ul><li>including custom made backgrounds and buttons</li></ul>
<li>Options menu<li>
  <ul><li>Including toggleable music and sound effects</li></ul>
  <li>Loading level page</li>
<li>Playable game</li>
<ul><li>Including custom animated running and jumping sprite for player character</li>
<li>Fully controlleable player character</li>
<li>custom made audio for game project</li></ul>
<li>Enemy class<li>
  <ul><li>Custom drawn enemy sprite</li></ul>
<li>Interactive platform<li>
  <ul><li>Able to collide with platforms and enemies</li></ul>
  </ul>
# How to run the Game 
  
To be able to see the graphics and hear the audio you will need to install the SFML library 
# Step One: Download SFML 
  # (https://www.sfml-dev.org/download/sfml/2.5.1/) 
You can download this from the SFML website, or we have included it in this GitHub. After downloading the latest 64 bit version. 
Navigate the location of the folder. 
# Step Two: Un-Zip SFML, preferably in your C Drive
![image](https://user-images.githubusercontent.com/92301718/170739050-8d7d1ab8-cb8a-4aa8-83cb-8e5db40d8cfd.png)
![image](https://user-images.githubusercontent.com/92301718/170739155-95e76c52-6423-498c-9080-014427fd2ed0.png) 
# Step Three: Locate Debugger properties 
![image](https://user-images.githubusercontent.com/92301718/170739474-112b7bea-4541-4132-b528-4b25638b4b7a.png) 
# Step Four: Locate C/C++ 
Additional Include Directories And change the text in the text box area to the following:
  
  C:\SFML-2.5.1\include;%(AdditionalIncludeDirectories) 
  
 So that it matches the location of your SFML\include file 
![image](https://user-images.githubusercontent.com/92301718/170739613-ea4127f6-ad0f-4cdf-a197-067b64c03e60.png)
  
# Step Five: Locate Linker General
  Next you are going to want to locate additional library directories and paste the following:
  
  C:\SFML-2.5.1\lib;%(AdditionalLibraryDirectories)
  
  Similar to the include directory section, you are going to want this to match the location of your SFML\lib folder
