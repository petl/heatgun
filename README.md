# heatgun

This project is a controller box for a really cheap heatgun I bought from ebay: http://www.ebay.com/itm/401129852165 .
It comes with an 8 pin 'DIN-style' microphone connector (http://www.vetco.net/catalog/product_info.php?products_id=6559), the pinout is on the bottom. The controller it was planned to use is the [858D](http://www.ebay.at/itm/220v-858D-Hot-Air-Rework-Digital-Station-Solder-Blower-Gun-Desoldering-Tool-DE-/131483067582), but with this configuration you ware much more flexible. 

I've added a [bill of materials (BOM)](https://github.com/petl/heatgun/blob/master/BOM.ods), most of the parts can be obtained on ebay for a fraction of the price. 

To get a feeling for the box take a look at the [photos](https://github.com/petl/heatgun/tree/master/photos) ([imgur album here](http://imgur.com/a/A3wa5)). 

Pinout:

| Pin        | Name     | 
| ------------- |:-------------:| 
| 1    | K type Thermocouple +  | 
| 2    | K type Thermocouple - |
| 3    | Standby switch      |
| 4    | Ground (earth) wire, connected to the steel tube|
| 5    | Fan -  |
| 6    | Fan + (12VDC) |
| 7    | Heating element     |
| 8    | Heating element |

<img src="https://github.com/petl/heatgun/blob/master/photos/conn.jpg" width="300">

The heating element is specified as 85 Ohm and has been measured as 83 Ohm (cold). 

Schematics are drawn in [eagle](https://cadsoft.io/), a snippet is here:

<img src="https://github.com/petl/heatgun/blob/master/photos/schem.png" width="300">


! I have to warn you about the connector type: The case mounted plug is male and has 230VAC on one of its pins! the design is for reference purpose only, build at your own risk. !
