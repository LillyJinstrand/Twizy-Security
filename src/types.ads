package types is

   -- 9 digits let's us represent 10^7m with cm accuracy
   type FixedNumber is digits 9;
   subtype Speed is FixedNumber range -80.0 .. 80.0;

end types;
