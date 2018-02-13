package body speedModule is

function speedtest(S : in Speed) return Boolean 
   is
      
   begin      
      
      if (0.0 <= S and then S <= 5.0) then

         return True;
      
         
      else
         
         return False;
      
      end if;

   end speedtest;
   end;
