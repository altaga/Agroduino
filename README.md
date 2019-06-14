# Agroduino

Media Video: https://www.youtube.com/watch?v=tqx6X_BFYPw&feature=youtu.be

<img src = "https://i.ibb.co/SV52wbc/DSC00016.jpg" width = "800">
<img src = "https://i.ibb.co/TMY93Sn/DSC00017.jpg" width = "800">
<img src = "https://i.ibb.co/qmQZ0Qr/DSC00018.jpg" width = "800">
<img src = "https://i.ibb.co/6PrMPTL/DSC00019.jpg" width = "800">

Summary
Agroduino is an IoT sensing, notifications, and analytics platform for urban and large-scale agriculture, with automated irrigation.

Documentation
Introduction:


Imagine a world where there is not enough food for you and your loved ones, an arid world where there is nothing to satisfy your hunger. Because of the current methods of agriculture, where excess fertilizers and pesticides have been used. These methods are not sustainable and we have to find new methods to optimize crops. Remember, we cannot create new land to grow crops, and the water reserves are being reduced each year. For that, Industry 3.0, with IoT, Big Data and predictive analysis solutions have to emerge to avoid this scenario from happening.



Problem:


Let's take a look at some FACTS:

• The population in Mexico (Both of the author's own country) and in the world will grow.

• By 2050 the production of food will have to DOUBLE to feed this population.

• The amount of arable Land will not increase.

• The amount of Water available will be decreasing.

• Sustainable Disruption is needed.

• Current methods are insufficient for this.

• Infrastructure is costly.

• Most fields are in remote areas.

• Urban agriculture needs a cheap and readily available solution, for it to be sustainable.

If only there was a way to monitor the field through a network of sustainable sensors, which could be monitored in real time 365 days a year, performing data analytics in the cloud and taking weather predictions to generate models. Taking all this information to manage resources such as water, in order to save most of them, and above all being powered by solar panels.



LET's BUILD IT!



Solution:


Our solution to the problem will be to create a sustainable platform of sensing and irrigation automation with predictive analysis via cloud. With one objective in mind: SAVE WATER.





Schematic of our proposed solution, explained below.



Bill of Materials:

Arduino MKR1400 GSM.
Moisture sensor.(preferably Capacitive)
DHT11 Sensor.
DS18B20 Sensor.
3 Resistances of 1kohm.
1 Resistance of 4.7kohm.
LiPo Rider Pro.(Driver Module for Baterry and Solar Cell).
Solar Cell (5V, 500mA).
Lithium Battery (3.7v, 500mA).
Cable, Solder, Jump wire or similar.
For the valve:

Arduino MKR1400 GSM.
TIP120
12v Source.
Solenoid Valve Nc 1/2.
Diode 1N4007.
1 Resistances of 2.2kohm.
Cable, Solder, Jump wire or similar.




1.- Using temperature with humidity, soil moisture and soil temperature sensors, we will use an Arduino MKR1400 GSM dev board with to obtain sensor data every 6 min. Cellular technology chosen because the characteristics of long range and low power are excellent for remote areas and cities alike.

Each batch of sensing is done at this frequency to send 120 packets per day and not keep the Cellular prices low.


For this system it was decided to use an Arduino board to obtain the data from the sensors (using the vast array of libraries from Arduino) and send them directly to a cloud service via MQTT (Namely Bluemix).


Then using the Openweathermap API and Node-RED we will create a Dashboard and notification capabilities.






On the image above you can see at: The main sensor circuit, with the Arduino MRK1400 and the sensors connected, also the solar power management.





The irrigation system circuit that uses another Arduino MRK1400 and a Solenoid Valve.



2.- We will send the data through a callback to the Thingspeak website through its API (more information in the link below).

Link: https://github.com/EddOliver/AggroFox/tree/master/Sigfox%20Configuration/Aggrofox%20Conf



3.- Once we have the data at Thingspeak, through the Thingspeak API we send the data to IBM Bluemix.

On the Bluemix platform, we made it possible to develop almost any application with the obtained data. (All the applications are based on Node Red to make the prototyping easier).
Examples of these applications:
			Generate databases of our crops and their conditions.

			Do data analysis to obtain predictive models in the long term.

			Water automation systems with the data obtained (as we will do in this project).

Crop yield analysis.
We decided to input first the data directly to thingspeak for its integration with Matlab and the posibility of creating data models in a future iteration.


3.1- We then will make a Dashboard with the data obtained for the complete and simple visualization of the data.



The dashboard will look like this one from another proyect we developed:









For the application, we will perform data crossing with the OpenWeatherMap API, to perform the control of an electrovalve connected to another Arduino MRK1400 microcontroller.


The data crossing obtained is used to check if that day is going to rain, and thus not use irrigation water in crops.


Also if the system detects that water is needed, in the field by the humidity sensors, the irrigation system is turned on.


In turn once a day an email will be sent to the farmer with the general information of his field or he can check anytime on his dashboard.


Also everytime the irrigation system is online, a notification will be sent.


In the images you can see an Hydroponic Chili,an Onion Culture and a Fig Tree, so YES we will be testing heavily the product.



This project will be a future iteration of a past project we already designed called Aggrofox:



 https://github.com/EddOliver/AggroFox



As you can see everything is detailed and further developed, but we want to validate and test a lot further now with Cellular technology.

With the boards we can improve hugely on this project!



One huge emphasis of these two projects is for them to also be used in Urban Agriculture and Cellular is the best choice for that one as we live in one of the biggest cities in the world (Mexico) and the reliability of Sigfox drops when you don't have line of sight. 





Manufacturing plans:


Everything will be done with a manufacturing-related mind. The prototype has to resist all kind of weather so the testing we will do will be done on several fronts. One front will be to validate that the data acquired by the system is the adecuate one, and perhaps to iterate further on that as the main aspect of the project is to save water and ease on the agricultural work. The other front will be related to the weather resistance of the project, we are using several modules by themselves and also a solar panel so everything has to be able to resist. We have access to several tools from our university to test all that and also our own software ones, and as the design will be based on 3D CAD software and other industrial tools the migration to manufacturing will be quick.





Deployment plan:


It basicallly will have three steps all based aroung testign the validity of the concept via crowdfunding.



-First we have to develop the PoC with cellular technology and test it fully, perhaps even make a few of those so we can have more users.

-Second is to start planning on the crowdfunding, this has to be done ahead of time about three to six months before it. This in order to properly concoct a plan of development, and get leads and marketing. And this period will serve for several other elements, from testing and iterating the PoC to developing visual aids for it.

-Third is the Crowdfunding itself, before it the product should have gone through various steps of testing. But, by itself a crowdfunding campaign is a very powerful validation tool, of the team, the product and the idea. It all depends really on how well the project does on this contest, but this is the main plan for the moment. What comes next is more on the business development side. By the way Arrow electronics offers a good way to help engineers during this kind of development on their certification program so getting this project on that before the Crowdfund would be part of the strategy.

