.PHONY: clean All

All:
	@echo "----------Building project:[ GEAR - Debug ]----------"
	@cd "GEAR" && "$(MAKE)" -f  "GEAR.mk" && "$(MAKE)" -f  "GEAR.mk" PostBuild
clean:
	@echo "----------Cleaning project:[ GEAR - Debug ]----------"
	@cd "GEAR" && "$(MAKE)" -f  "GEAR.mk" clean
