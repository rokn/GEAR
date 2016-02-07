.PHONY: clean All

All:
	@echo "----------Building project:[ GEAR - Release ]----------"
	@cd "GEAR" && "$(MAKE)" -f  "GEAR.mk"
clean:
	@echo "----------Cleaning project:[ GEAR - Release ]----------"
	@cd "GEAR" && "$(MAKE)" -f  "GEAR.mk" clean
