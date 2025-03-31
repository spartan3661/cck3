CXX =  g++-14.2.0 -std=c++20 -fmodules-ts
CXXFLAGS = -Wall -g
HEADERFLAGS = -c -x c++-system-header
SOURCES = Objects/Currency/Currency.cc \
          Objects/Currency/Currency-impl.cc \
          Objects/Position/Position.cc \
          Objects/Position/Position-impl.cc \
          Base\ Classes/Subject-Observer/Subject-Observer.cc \
          Base\ Classes/Subject-Observer/Subject-Observer-impl.cc \
		  Base\ Classes/Passive/Passive.cc \
		  Base\ Classes/Passive/Passive-impl.cc \
		  Base\ Classes/Entity/Entity.cc \
		  Base\ Classes/Entity/Entity-impl.cc \
		  Base\ Classes/LivingEntity/LivingEntity.cc \
		  Base\ Classes/LivingEntity/LivingEntity-impl.cc \
		  Base\ Classes/StatusEffect/StatusEffect.cc \
		  Base\ Classes/StatusEffect/StatusEffect-impl.cc \
		  Base\ Classes/Item/Item.cc \
		  Base\ Classes/Item/Item-impl.cc \
		  Objects/Player/Player.cc \
		  Objects/Player/Player-impl.cc \
		  Objects/Enemy/Enemy.cc \
		  Objects/Enemy/Enemy-impl.cc \
		  Objects/Items/BarrierSuit.cc \
		  Objects/Items/BarrierSuit-impl.cc \
		  Objects/Items/Compass.cc \
		  Objects/Items/Compass-impl.cc \
		  Objects/Items/GoldPile.cc \
		  Objects/Items/GoldPile-impl.cc \
		  Objects/Items/Potion.cc \
		  Objects/Items/Potion-impl.cc \
		  Objects/PotionEffects/HealthEffect.cc \
		  Objects/PotionEffects/HealthEffect-impl.cc \
		  Objects/PotionEffects/AtkEffect.cc \
		  Objects/PotionEffects/AtkEffect-impl.cc \
		  Objects/PotionEffects/DefEffect.cc \
		  Objects/PotionEffects/DefEffect-impl.cc \
		  Objects/Enemy/Merchant.cc \
		  Objects/Enemy/Merchant-impl.cc \
		  Objects/Enemy/Dragon.cc \
		  Objects/Enemy/Dragon-impl.cc \
		  Objects/TextDisplay/TextDisplay.cc \
		  Objects/TextDisplay/TextDisplay-impl.cc \
		  Objects/Board/Board.cc \
		  Objects/Board/Board-impl.cc \
          main.cc
# list of all .cc files in the current directory

HEADERS = iostream vector compare fstream tuple algorithm random cmath memory string
EXEC = submission

$(EXEC): $(SOURCES)
	rm -rf gcm.cache
	$(CXX) $(HEADERFLAGS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXEC)
	rm -rf gcm.cache

.PHONY: clean 
clean:
	rm -r ./gcm.cache
	rm -f $(EXEC)