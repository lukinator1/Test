// Fill out your copyright notice in the Description page of Project Settings.


#include "DarkTouch.h"
ADarkTouch::ADarkTouch(){
    static ConstructorHelpers::FObjectFinder<UNiagaraSystem> darktouchparticlesystemasset(TEXT("NiagaraSystem'/Game/Blueprints/DarkTouchNiagara.DarkTouchNiagara'"));
    particlesystem = darktouchparticlesystemasset.Object;
    static ConstructorHelpers::FObjectFinder<UAnimMontage> darktouchanimationasset(TEXT("AnimMontage'/Game/ParagonRevenant/Characters/Heroes/Revenant/Animations/DarkTouchAnimation.DarkTouchAnimation'"));
    spellanimation = darktouchanimationasset.Object;
    static ConstructorHelpers::FObjectFinder<USoundWave> spellcastsoundasset(TEXT("SoundWave'/Game/Blueprints/darktouchsound__1_.darktouchsound__1_'"));
    spellcastsound = spellcastsoundasset.Object;
    windup = .15f;
    cooldown = .35f;
}

void ADarkTouch::Cast_Implementation(){
    //Protagonist *caster = (Protagonist *)GetInstigator();
    //GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Darktouch");
    FVector startloc = camera->GetComponentLocation() + camera->GetComponentRotation().RotateVector(FVector(40.0f, 0.0f, 0.0f));
    FVector endloc = camera->GetComponentLocation() + camera->GetComponentRotation().RotateVector(FVector(2000.0f, 0.0f, 0.0f));
    FHitResult hitresult;
    UWorld* world;
    world = GetWorld();
    DrawDebugLine(world, startloc, endloc, FColor::Green, false, 5.0f, ECC_WorldStatic, 0.75f);
    if (world->LineTraceSingleByChannel(hitresult, startloc, endloc, ECollisionChannel::ECC_GameTraceChannel2)){
    AEnemy *enemy = static_cast<AEnemy*>(hitresult.GetActor());
    //hitresult.GetActor()->K2_DestroyActor();
        enemy->takeDamageOverTime(dmg, 1.33f, 5.0f);
        //FTimerManager timermanager;
        //FTimerHandle timerhandle;
        //timermanager.SetTimer(timerhandle, , 5.0f, false, 0.0f);
    }
}
