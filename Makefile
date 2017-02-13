.PHONY: clean All

All:
	@echo "----------Building project:[ LabJ - Debug ]----------"
	@cd "LabJ" && "$(MAKE)" -f  "LabJ.mk"
clean:
	@echo "----------Cleaning project:[ LabJ - Debug ]----------"
	@cd "LabJ" && "$(MAKE)" -f  "LabJ.mk" clean
