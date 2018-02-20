package types is

   type FixedNumber is delta 0.01 digits 6;
   subtype Speed is FixedNumber range -80.0 .. 80.0;

end types;
