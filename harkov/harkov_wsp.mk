.PHONY: clean All

All:
	@echo "----------Building project:[ harkov - Debug ]----------"
	@$(MAKE) -f  "harkov.mk"
clean:
	@echo "----------Cleaning project:[ harkov - Debug ]----------"
	@$(MAKE) -f  "harkov.mk" clean
