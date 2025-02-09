// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PEBlueprintAsset.generated.h"


USTRUCT(BlueprintType)
struct FPEGraphTerminalType
{
public:
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName PinCategory;
     
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* PinSubCategoryObject;
};

USTRUCT(BlueprintType)
struct FPEGraphPinType
{
public:
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName PinCategory;
     
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* PinSubCategoryObject;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int PinContainerType;
        
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsReference;
};


/**
 * 
 */
UCLASS()
class PUERTSEDITOR_API UPEBlueprintAsset : public UObject
{
	GENERATED_BODY()
	
public:

    UPROPERTY(BlueprintReadOnly)
    UClass* GeneratedClass;

    UPROPERTY(BlueprintReadOnly)
    UBlueprint* Blueprint;

    UPROPERTY(BlueprintReadOnly)
    UPackage* Package;

    UFUNCTION(BlueprintCallable, Category = "PEBlueprintAsset")
    bool IsExisted(const FString& InName, const FString& InPath);

    UFUNCTION(BlueprintCallable, Category = "PEBlueprintAsset")
    bool Load(const FString& InParentClassName, const FString& InName, const FString& InPath);

    UFUNCTION(BlueprintCallable, Category = "PEBlueprintAsset")
    void AddParameter(FName InParameterName, FPEGraphPinType InGraphPinType, FPEGraphTerminalType InPinValueType);

    UFUNCTION(BlueprintCallable, Category = "PEBlueprintAsset")
    void ClearParameter();

    UFUNCTION(BlueprintCallable, Category = "PEBlueprintAsset")
    void AddFunction(FName InName, bool IsVoid, FPEGraphPinType InGraphPinType, FPEGraphTerminalType InPinValueType);

    UFUNCTION(BlueprintCallable, Category = "PEBlueprintAsset")
    void RemoveNotExistedFunction();

    UFUNCTION(BlueprintCallable, Category = "PEBlueprintAsset")
    void AddMemberVariable(FName NewVarName, FPEGraphPinType InGraphPinType, FPEGraphTerminalType InPinValueType);

    UFUNCTION(BlueprintCallable, Category = "PEBlueprintAsset")
    void RemoveNotExistedMemberVariable();

    UFUNCTION(BlueprintCallable, Category = "PEBlueprintAsset")
    void Save();

private:
    TSet<FName> MemberVariableAdded;

    TSet<FName> FunctionAdded;

    TArray<FName> ParameterNames;

    TArray<FEdGraphPinType> ParameterTypes;
};
