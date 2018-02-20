pragma SPARK_Mode(ON);

package gpsModule with SPARK_Mode is

   type Lon is delta 10.0**(-15) range -180.0 .. 180.0;
   type Lat is delta 10.0**(-15) range -90.0 .. 90.0;
   
   type box is 
      record
         top_left_lat : Lat;
         bottom_right_lat : Lat;
         bottom_right_lon : Lon;
         top_left_lon : Lon;
      end record;
   
   function gpstest(X : in Lat; Y : in Lon) return Boolean with
    Post => (if gpstest'Result then X >= 57.68699206426933 and X <= 57.688440132300684 and Y >= 11.97746068239212 and Y <= 11.981237232685089) and
    (if not gpstest'Result then X < 57.68699206426933 or X > 57.688440132300684 or Y < 11.97746068239212 or Y > 11.981237232685089),
     Global => null;

end gpsModule;
