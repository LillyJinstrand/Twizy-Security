package types is

   -- 9 digits let's us represent 10^10m with cm accuracy
   type FloatingNumber is digits 12;
   subtype Speed is FloatingNumber range -80.0 .. 80.0;

end types;
