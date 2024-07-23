// Copyright 2024 Cajun Pro LLC. All Rights Reserved.


#include "RubberbandFunctionLibrary.h"

#include "Blueprint/SlateBlueprintLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/Widget.h"
#include "Kismet/KismetMathLibrary.h"

void URubberbandFunctionLibrary::GetTransform(UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform) {}

void URubberbandFunctionLibrary::OneSide(UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform) {}

void URubberbandFunctionLibrary::OneCorner(UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform) {}

void URubberbandFunctionLibrary::OpposingSides(UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform) {}

void URubberbandFunctionLibrary::ThreeSides(UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform) {}

void URubberbandFunctionLibrary::AllSides(UWidget* Widget, const float Alpha, bool& bUnchanged, FVector2D& Transform)
{
	Transform = FVector2D(UKismetMathLibrary::Lerp(GetWX(Widget), 0.0f, Alpha),UKismetMathLibrary::Lerp(GetWY(Widget), 0, Alpha));
	bool Changed = GetWLeft(Widget) > GetVLeft(Widget) && GetWTop(Widget) > GetVTop(Widget) && GetWRight(Widget) < GetVRight(Widget) && GetWBottom(Widget) < GetVBottom(Widget);
	bUnchanged = !Changed;
}

float URubberbandFunctionLibrary::GetVTop(UWidget* Widget) { return 0.0f; }

float URubberbandFunctionLibrary::GetVLeft(UWidget* Widget) { return 0.0f; }

float URubberbandFunctionLibrary::GetVRight(UWidget* Widget) { return Widget ? UWidgetLayoutLibrary::GetViewportSize(Widget).X : 0.0f; }

float URubberbandFunctionLibrary::GetVBottom(UWidget* Widget) { return Widget ? UWidgetLayoutLibrary::GetViewportSize(Widget).Y : 0.0f; }

float URubberbandFunctionLibrary::GetWX(const UWidget* Widget) { return Widget ? Widget->GetRenderTransform().Translation.X : 0.0f; }

float URubberbandFunctionLibrary::GetWY(const UWidget* Widget) { return Widget ? Widget->GetRenderTransform().Translation.Y : 0.0f; }

float URubberbandFunctionLibrary::GetWLeft(UWidget* Widget)
{
	if (Widget)
	{
		FVector2D PixelPosition;
		FVector2D ViewportPosition;
		USlateBlueprintLibrary::LocalToViewport(Widget, Widget->GetCachedGeometry(), { 0, 0 }, PixelPosition, ViewportPosition);
		return PixelPosition.X;
	}
	return 0.0f;
}

float URubberbandFunctionLibrary::GetWTop(UWidget* Widget)
{
	if (Widget)
	{
		FVector2D PixelPosition;
		FVector2D ViewportPosition;
		USlateBlueprintLibrary::LocalToViewport(Widget, Widget->GetCachedGeometry(), { 0, 0 }, PixelPosition, ViewportPosition);
		return PixelPosition.Y;
	}
	return 0.0f;
}

float URubberbandFunctionLibrary::GetWRight(UWidget* Widget)
{
	if (Widget)
	{
		FVector2D PixelPosition;
		FVector2D ViewportPosition;
		USlateBlueprintLibrary::LocalToViewport(Widget, Widget->GetCachedGeometry(), Widget->GetDesiredSize(), PixelPosition, ViewportPosition);
		return PixelPosition.X;
	}
	return 0.0f;
}

float URubberbandFunctionLibrary::GetWBottom(UWidget* Widget)
{
	if (Widget)
	{
		FVector2D PixelPosition;
		FVector2D ViewportPosition;
		USlateBlueprintLibrary::LocalToViewport(Widget, Widget->GetCachedGeometry(), Widget->GetDesiredSize(), PixelPosition, ViewportPosition);
		return PixelPosition.Y;
	}
	return 0.0f;
}