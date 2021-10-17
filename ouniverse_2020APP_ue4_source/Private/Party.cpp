// Fill out your copyright notice in the Description page of Project Settings.


#include "Party.h"
#include "APC.h"
#include "ACM.h"
#include "Actra.h"

void UPartyMember::Setup(int InIndex)
{
    Index = InIndex;
}

void UPartyMember::SetAdjacent(UPartyMember* InNext, UPartyMember* InPrevious)
{
    Previous = InPrevious;
    Next = InNext;
}

UPartyMember* UPartyMember::GetNextAvailable(bool bReverse)
{
    if (!bReverse)
    {
        return Next->GetNextAvailableIterator(Index, bReverse);
    }
    else
    {
        return Previous->GetNextAvailableIterator(Index,bReverse);
    }
}

UPartyMember* UPartyMember::GetNextAvailableIterator(int StartIndex, bool bReverse)
{
    if (StartIndex == Index)
    {
        return this;
    }
    else
    {
        if (IsAvailableForPlayer())
        {
            return this;
        }
        else
        {
            if (!bReverse)
            {
                return Next->GetNextAvailableIterator(StartIndex, bReverse);
            }
            else
            {
                return Previous->GetNextAvailableIterator(StartIndex, bReverse);
            }
        }
    }
}

void UPartyMember::SetActra(AActra* InMember)
{
    Member = InMember;
}

void UPartyMember::ConnectPlayer(APC* InPC)
{
    PC = InPC;
    if (IsValid(PC->PartyMember))
    {
        PC->PartyMember->DisconnectPlayer();
    }
    PC->PartyMember = this;
    PC->Pilot(Member);
    ACM* CM = PC->GetCM();
    UCamTweenPartyShift* ActiveTween = NewObject<UCamTweenPartyShift>();
    ActiveTween->Setup(PC, CM, Member, CM->LastFrameVT, Member->FollowCamera, 0.45f);
    CM->RunTween(ActiveTween);
}

void UPartyMember::DisconnectPlayer()
{
    PC->PartyMember = NULL;
    PC = NULL;
}

void UPartyMember::ConnectSpectator(APC* InPC)
{

}

bool UPartyMember::IsAvailableForPlayer()
{
    if (!IsEmpty() && PC == NULL)
    {
        return true;
    }

    return false;
}

bool UPartyMember::IsEmpty()
{
    if (Member == NULL)
    {
        return true;
    }

    return false;
}

UPartyMember* AParty::GetPartyMember(int Index)
{
    return PartyMembers[Index];
}



AParty::AParty()
{
    UPartyMember* N;
    N = CreateDefaultSubobject<UPartyMember>(TEXT("PartyMember0"));
    PartyMembers.Add(N);
    N->Setup(0);
    N = CreateDefaultSubobject<UPartyMember>(TEXT("PartyMember1"));
    PartyMembers.Add(N);
    N->Setup(1);
    N = CreateDefaultSubobject<UPartyMember>(TEXT("PartyMember2"));
    PartyMembers.Add(N);
    N->Setup(2);

    PartyMembers[0]->SetAdjacent(PartyMembers[2],PartyMembers[1]);
    PartyMembers[1]->SetAdjacent(PartyMembers[0], PartyMembers[2]);
    PartyMembers[2]->SetAdjacent(PartyMembers[1], PartyMembers[0]);
}

void AParty::ConnectToParty(APC* PC)
{

    bool bHasPlayer = false;
    for (int i = 0; i < 3; i++)
    {
        if (PartyMembers[i]->PC != NULL)
        {
            bHasPlayer = true;
            break;
        }

    }

    if(!bHasPlayer)
    {
        PartyMembers[0]->ConnectPlayer(PC);
    }

}