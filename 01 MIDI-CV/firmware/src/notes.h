#pragma once

// Calibrated DAC values to generate correct CV voltages for each notes
// MIDI note 60 outputs 1.0V (2.0V with op-amp gain)
// 12 notes / octaves
const int g_notes[97] = 
{
    // C1: 36 - 47
    0, 42, 83, 125, 167, 208, 250, 292, 333, 375, 417, 458,

    // C2: 48 - 59
    500, 542, 583, 625, 667, 708, 750, 792, 833, 875, 917, 958,

    // C3: 60 - 71
    1000, 1042, 1083, 1125, 1167, 1208, 1250, 1292, 1333, 1375, 1417, 1458,
	
    // C4: 72 - 83								
    1500, 1542, 1583, 1625, 1667, 1708, 1750, 1792, 1833, 1875, 1917, 1958,
	
    // C5: 84 - 95				
    2000, 2042, 2083, 2125, 2167, 2208, 2250, 2292, 2333, 2375, 2417, 2458,
	
    // C6: 96 - 107
    2500, 2542, 2583, 2625, 2667, 2708, 2750, 2792, 2833, 2875, 2917, 2958,
	
    // C7: 108 - 119			
    3000, 3042, 3083, 3125, 3167, 3208, 3250, 3292, 3333, 3375, 3417, 3458,

    // C8: 120 - 131
    3500, 3542, 3583, 3625, 3667, 3708, 3750, 3792, 3833, 3875, 3917, 3958,

    // C9: 132
    4000
};