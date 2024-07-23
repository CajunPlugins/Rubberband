// Copyright 2024 Cajun Pro LLC. All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "RubberbandFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintThreadSafe, DisplayName="Rubberband Function Library", ScriptName="RubberbandFunctionLibrary"))
class RUBBERBAND_API URubberbandFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category="Rubberband")
	static void GetTransform(class UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform);

	UFUNCTION(BlueprintPure, Category="Rubberband")
	static void OneSide(class UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform);

	UFUNCTION(BlueprintPure, Category="Rubberband")
	static void OneCorner(class UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform);

	UFUNCTION(BlueprintPure, Category="Rubberband")
	static void OpposingSides(class UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform);

	UFUNCTION(BlueprintPure, Category="Rubberband", meta=(DisplayName="3 Sides"))
	static void ThreeSides(class UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform);

	UFUNCTION(BlueprintPure, Category="Rubberband")
	static void AllSides(class UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform);

protected:
	static float GetVTop(class UWidget* Widget);
	static float GetVLeft(class UWidget* Widget);
	static float GetVRight(class UWidget* Widget);
	static float GetVBottom(class UWidget* Widget);
	static float GetWX(const class UWidget* Widget);
	static float GetWY(const class UWidget* Widget);
	static float GetWLeft(class UWidget* Widget);
	static float GetWTop(class UWidget* Widget);
	static float GetWRight(class UWidget* Widget);
	static float GetWBottom(class UWidget* Widget);
};
