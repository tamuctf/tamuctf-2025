from brain import Brain

healthy_brain = [[71, 101, 18, 37, 41, 69, 80, 28, 23, 48], [35, 32, 44, 24, 27, 20, 34, 58, 24, 9], [73, 29, 37, 94, 27, 58, 104, 65, 116, 44], [26, 83, 77, 116, 9, 96, 111, 118, 52, 62], [100, 15, 119, 53, 59, 34, 38, 68, 104, 110], [51, 1, 54, 62, 56, 120, 4, 80, 60, 120], [125, 92, 95, 98, 97, 110, 93, 33, 128, 93], [70, 23, 123, 40, 75, 23, 104, 73, 52, 6], [14, 11, 99, 16, 124, 52, 14, 73, 47, 66], [128, 11, 49, 111, 64, 108, 14, 66, 128, 101]]
brainrot = b"Skibidi, Skibidi toilet, gyatt, mewing, mew, rizz, rizzing, rizzler, on Skibidi, sigma, what the sigma, Ohio, bussin, cook, cooking, let him/her cook, baddie, chill guy, Skibidi rizz, fanum tax, Fanum taxing, drake, nonchalant dread head, aura, uncanny, grimace shake, freddy five bear, edging, edge, goon, gooning, looksmaxxing, alpha, griddy, diddy, low taper fade, Put the fries in the bag, what's up brother, baby gronk, livvy dunne, on skib, duke Dennis, I see trees of breen, oh when the saints go marching in, blud, lil bro, bite the curb, bazinga, brisket song. English or Spanish, 5 nights at diddys, devious lick, Fanta in my system song, Qaundale dingle, Sus, sussy, imposter, among us, nugget, TikTok rizz party, oi oi oi, Reese's pieces and life saver gummies meme, devious, Ei ei ei, ratio, L, L bozo, L + ratio, brain rot, ishowspeed, bing chilling, bomboclatt,mog, mogging, yap, yapping, yapper, sticking out your gyatt for the rizzler, caseoh, goonmaxing, Freddy fazbear, Kai cenat, Harlem shake, glizzy, Smurf cat, Kai cenat rizz, digital circus, 1 2 buckle my shoe, oil up, did you pray today, cap, stop the cap, Ohio, only in Ohio, absolute cinema, lobotomy, eeffoc, idksterling"

brain = Brain(healthy_brain)
brain.rot(brainrot)

required_thoughts = [
    [59477, 41138, 59835, 73146, 77483, 59302, 102788, 67692, 62102, 85259],
    [40039, 59831, 72802, 77436, 57296, 101868, 69319, 59980, 84518, 73579466],
    [59783, 73251, 76964, 58066, 101937, 68220, 59723, 85312, 73537261, 7793081533],
    [71678, 77955, 59011, 102453, 66381, 60215, 86367, 74176247, 9263142620, 982652150581],
]

import numpy as np
m = np.array(brain.neurons)

dec = [0] * 40
for i in range(0, 40, 10):
    dec[i:i+10] = [round(x) for x in np.linalg.solve(m, required_thoughts[i//10])]
    brain.think(dec[i:i+10])
    m = np.array(brain.neurons)

print(bytes(dec))