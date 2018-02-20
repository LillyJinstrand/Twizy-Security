package body gpsmodule with SPARK_Mode is

   chalmers : constant box := (bottom_right_lon => 11.981237232685089,
                bottom_right_lat => 57.68699206426933,
                top_left_lat => 57.688440132300684,
                top_left_lon => 11.97746068239212);
   
   function gpstest(X : in Lat; Y : in Lon) return Boolean
   is
   begin      
      if (X <= chalmers.top_left_lat and then 
          chalmers.bottom_right_lat <= X and then
          Y >= chalmers.top_left_lon and then
          chalmers.bottom_right_lon >= Y) then
         return True;
      else
         return False;
      end if;
   end gpstest;
   end;
