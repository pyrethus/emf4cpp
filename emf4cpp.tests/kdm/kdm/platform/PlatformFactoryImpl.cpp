// -*- mode: c++; c-basic-style: "bsd"; c-basic-offset: 4; -*-
/*
 * kdm/platform/PlatformFactoryImpl.cpp
 * Copyright (C) Cátedra SAES-UMU 2010 <andres.senac@um.es>
 * Copyright (C) INCHRON GmbH 2016-2019 <emf4cpp@inchron.com>
 * Copyright (C) INCHRON AG 2019-2021 <emf4cpp@inchron.com>
 *
 * EMF4CPP is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * EMF4CPP is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <kdm/platform/PlatformFactory.hpp>
#include <kdm/platform/PlatformPackage.hpp>
#include <kdm/platform/AbstractPlatformElement.hpp>
#include <kdm/platform/PlatformModel.hpp>
#include <kdm/platform/AbstractPlatformRelationship.hpp>
#include <kdm/platform/Requires.hpp>
#include <kdm/platform/ResourceType.hpp>
#include <kdm/platform/NamingResource.hpp>
#include <kdm/platform/MarshalledResource.hpp>
#include <kdm/platform/MessagingResource.hpp>
#include <kdm/platform/FileResource.hpp>
#include <kdm/platform/ExecutionResource.hpp>
#include <kdm/platform/PlatformAction.hpp>
#include <kdm/platform/ExternalActor.hpp>
#include <kdm/platform/DataManager.hpp>
#include <kdm/platform/BindsTo.hpp>
#include <kdm/platform/PlatformElement.hpp>
#include <kdm/platform/PlatformRelationship.hpp>
#include <kdm/platform/PlatformEvent.hpp>
#include <kdm/platform/LockResource.hpp>
#include <kdm/platform/DeployedSoftwareSystem.hpp>
#include <kdm/platform/Machine.hpp>
#include <kdm/platform/DeployedComponent.hpp>
#include <kdm/platform/DeployedResource.hpp>
#include <kdm/platform/Loads.hpp>
#include <kdm/platform/Spawns.hpp>
#include <kdm/platform/RuntimeResource.hpp>
#include <kdm/platform/Thread.hpp>
#include <kdm/platform/Process.hpp>
#include <kdm/platform/ReadsResource.hpp>
#include <kdm/platform/WritesResource.hpp>
#include <kdm/platform/ManagesResource.hpp>
#include <kdm/platform/DefinedBy.hpp>
#include <kdm/platform/StreamResource.hpp>

#include <ecore.hpp>
#include <ecorecpp/mapping.hpp>

using namespace ::kdm::platform;

PlatformFactory::PlatformFactory()
{
}

::ecore::EObject_ptr PlatformFactory::create(::ecore::EClass_ptr _eClass)
{
    switch (_eClass->getClassifierID())
    {
    case PlatformPackage::ABSTRACTPLATFORMELEMENT:
        return createAbstractPlatformElement();
    case PlatformPackage::PLATFORMMODEL:
        return createPlatformModel();
    case PlatformPackage::ABSTRACTPLATFORMRELATIONSHIP:
        return createAbstractPlatformRelationship();
    case PlatformPackage::REQUIRES:
        return createRequires();
    case PlatformPackage::RESOURCETYPE:
        return createResourceType();
    case PlatformPackage::NAMINGRESOURCE:
        return createNamingResource();
    case PlatformPackage::MARSHALLEDRESOURCE:
        return createMarshalledResource();
    case PlatformPackage::MESSAGINGRESOURCE:
        return createMessagingResource();
    case PlatformPackage::FILERESOURCE:
        return createFileResource();
    case PlatformPackage::EXECUTIONRESOURCE:
        return createExecutionResource();
    case PlatformPackage::PLATFORMACTION:
        return createPlatformAction();
    case PlatformPackage::EXTERNALACTOR:
        return createExternalActor();
    case PlatformPackage::DATAMANAGER:
        return createDataManager();
    case PlatformPackage::BINDSTO:
        return createBindsTo();
    case PlatformPackage::PLATFORMELEMENT:
        return createPlatformElement();
    case PlatformPackage::PLATFORMRELATIONSHIP:
        return createPlatformRelationship();
    case PlatformPackage::PLATFORMEVENT:
        return createPlatformEvent();
    case PlatformPackage::LOCKRESOURCE:
        return createLockResource();
    case PlatformPackage::DEPLOYEDSOFTWARESYSTEM:
        return createDeployedSoftwareSystem();
    case PlatformPackage::MACHINE:
        return createMachine();
    case PlatformPackage::DEPLOYEDCOMPONENT:
        return createDeployedComponent();
    case PlatformPackage::DEPLOYEDRESOURCE:
        return createDeployedResource();
    case PlatformPackage::LOADS:
        return createLoads();
    case PlatformPackage::SPAWNS:
        return createSpawns();
    case PlatformPackage::RUNTIMERESOURCE:
        return createRuntimeResource();
    case PlatformPackage::THREAD:
        return createThread();
    case PlatformPackage::PROCESS:
        return createProcess();
    case PlatformPackage::READSRESOURCE:
        return createReadsResource();
    case PlatformPackage::WRITESRESOURCE:
        return createWritesResource();
    case PlatformPackage::MANAGESRESOURCE:
        return createManagesResource();
    case PlatformPackage::DEFINEDBY:
        return createDefinedBy();
    case PlatformPackage::STREAMRESOURCE:
        return createStreamResource();
    default:
        throw "IllegalArgumentException";
    }
}

::ecore::EJavaObject PlatformFactory::createFromString(
        ::ecore::EDataType_ptr _eDataType,
        ::ecore::EString const &_literalValue)
{
    switch (_eDataType->getClassifierID())
    {
    default:
        throw "IllegalArgumentException";
    }
}

::ecore::EString PlatformFactory::convertToString(
        ::ecore::EDataType_ptr _eDataType,
        ::ecore::EJavaObject const &_instanceValue)
{
    switch (_eDataType->getClassifierID())
    {
    default:
        throw "IllegalArgumentException";
    }
}

AbstractPlatformElement_ptr PlatformFactory::createAbstractPlatformElement()
{
    return ::ecore::Ptr < AbstractPlatformElement
            > (new AbstractPlatformElement);
}
PlatformModel_ptr PlatformFactory::createPlatformModel()
{
    return ::ecore::Ptr < PlatformModel > (new PlatformModel);
}
AbstractPlatformRelationship_ptr PlatformFactory::createAbstractPlatformRelationship()
{
    return ::ecore::Ptr < AbstractPlatformRelationship
            > (new AbstractPlatformRelationship);
}
Requires_ptr PlatformFactory::createRequires()
{
    return ::ecore::Ptr < Requires > (new Requires);
}
ResourceType_ptr PlatformFactory::createResourceType()
{
    return ::ecore::Ptr < ResourceType > (new ResourceType);
}
NamingResource_ptr PlatformFactory::createNamingResource()
{
    return ::ecore::Ptr < NamingResource > (new NamingResource);
}
MarshalledResource_ptr PlatformFactory::createMarshalledResource()
{
    return ::ecore::Ptr < MarshalledResource > (new MarshalledResource);
}
MessagingResource_ptr PlatformFactory::createMessagingResource()
{
    return ::ecore::Ptr < MessagingResource > (new MessagingResource);
}
FileResource_ptr PlatformFactory::createFileResource()
{
    return ::ecore::Ptr < FileResource > (new FileResource);
}
ExecutionResource_ptr PlatformFactory::createExecutionResource()
{
    return ::ecore::Ptr < ExecutionResource > (new ExecutionResource);
}
PlatformAction_ptr PlatformFactory::createPlatformAction()
{
    return ::ecore::Ptr < PlatformAction > (new PlatformAction);
}
ExternalActor_ptr PlatformFactory::createExternalActor()
{
    return ::ecore::Ptr < ExternalActor > (new ExternalActor);
}
DataManager_ptr PlatformFactory::createDataManager()
{
    return ::ecore::Ptr < DataManager > (new DataManager);
}
BindsTo_ptr PlatformFactory::createBindsTo()
{
    return ::ecore::Ptr < BindsTo > (new BindsTo);
}
PlatformElement_ptr PlatformFactory::createPlatformElement()
{
    return ::ecore::Ptr < PlatformElement > (new PlatformElement);
}
PlatformRelationship_ptr PlatformFactory::createPlatformRelationship()
{
    return ::ecore::Ptr < PlatformRelationship > (new PlatformRelationship);
}
PlatformEvent_ptr PlatformFactory::createPlatformEvent()
{
    return ::ecore::Ptr < PlatformEvent > (new PlatformEvent);
}
LockResource_ptr PlatformFactory::createLockResource()
{
    return ::ecore::Ptr < LockResource > (new LockResource);
}
DeployedSoftwareSystem_ptr PlatformFactory::createDeployedSoftwareSystem()
{
    return ::ecore::Ptr < DeployedSoftwareSystem > (new DeployedSoftwareSystem);
}
Machine_ptr PlatformFactory::createMachine()
{
    return ::ecore::Ptr < Machine > (new Machine);
}
DeployedComponent_ptr PlatformFactory::createDeployedComponent()
{
    return ::ecore::Ptr < DeployedComponent > (new DeployedComponent);
}
DeployedResource_ptr PlatformFactory::createDeployedResource()
{
    return ::ecore::Ptr < DeployedResource > (new DeployedResource);
}
Loads_ptr PlatformFactory::createLoads()
{
    return ::ecore::Ptr < Loads > (new Loads);
}
Spawns_ptr PlatformFactory::createSpawns()
{
    return ::ecore::Ptr < Spawns > (new Spawns);
}
RuntimeResource_ptr PlatformFactory::createRuntimeResource()
{
    return ::ecore::Ptr < RuntimeResource > (new RuntimeResource);
}
Thread_ptr PlatformFactory::createThread()
{
    return ::ecore::Ptr < Thread > (new Thread);
}
Process_ptr PlatformFactory::createProcess()
{
    return ::ecore::Ptr < Process > (new Process);
}
ReadsResource_ptr PlatformFactory::createReadsResource()
{
    return ::ecore::Ptr < ReadsResource > (new ReadsResource);
}
WritesResource_ptr PlatformFactory::createWritesResource()
{
    return ::ecore::Ptr < WritesResource > (new WritesResource);
}
ManagesResource_ptr PlatformFactory::createManagesResource()
{
    return ::ecore::Ptr < ManagesResource > (new ManagesResource);
}
DefinedBy_ptr PlatformFactory::createDefinedBy()
{
    return ::ecore::Ptr < DefinedBy > (new DefinedBy);
}
StreamResource_ptr PlatformFactory::createStreamResource()
{
    return ::ecore::Ptr < StreamResource > (new StreamResource);
}

