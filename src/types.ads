package types is

   type FixedNumber is delta 0.01 range -1000.0 .. 1000.0;
   subtype Speed is FixedNumber range -80.0 .. 80.0;

end types;
