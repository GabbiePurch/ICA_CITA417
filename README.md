#Lab 1 Architecture:
1) My component allows a designer to add health, damage, and healing to different actors all with their own number for health, how much damage, and how much healing.
2) I kept the core health logic inside the c++. This includes Currenthealth, MaxHealth, ApplyDamage(), health(), etc.
3) I exposed MaxHealth to the blueprint so designers can configure different health values for different actors without
changing the actual C++. I also exposed ApplyDamage(), and Heal() to the blueprint so the logic can trigger health changes.
4) The extension I added was an event to State that the actor (which ever one it was) has died when their health hit zero, it's a death event.
